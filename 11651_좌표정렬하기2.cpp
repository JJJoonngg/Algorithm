/*
https://www.acmicpc.net/problem/11651
����
2���� ��� ���� �� N���� �־�����. ��ǥ�� y��ǥ�� �����ϴ� ������, y��ǥ�� ������ x��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����.
(-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.
5
0 4
1 2
1 -1
2 2
3 3
���
ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.
1 -1
1 2
2 2
3 3
0 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct xy { int x; int y; };
vector<xy> v;
bool comp(xy tmp1, xy tmp2) {
	if (tmp1.y == tmp2.y) return tmp1.x < tmp2.x;
	else return tmp1.y < tmp2.y;
}
int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) cout << v[i].x << " " << v[i].y << "\n";
}