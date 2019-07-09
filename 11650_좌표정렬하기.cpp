/*
����
2���� ��� ���� �� N���� �־�����. ��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����.
(-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.
5
3 4
1 1
1 -1
2 2
3 3
���
ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.
1 -1
1 1
2 2
3 3
3 4
�˰��� �з� : ����
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct xy { int x; int y; };
bool comp(xy v1, xy v2) {
	if (v1.x == v2.x) return v1.y < v2.y;
	else return v1.x < v2.x;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<xy> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) cout << v[i].x << " " << v[i].y << "\n";
}