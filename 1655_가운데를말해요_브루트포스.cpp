/*
https://www.acmicpc.net/problem/1655
�Է�
ù° �ٿ��� �����̰� ��ġ�� ������ ���� N�� �־�����. N�� 1���� ũ�ų� ����, 100,000���� �۰ų� ���� �ڿ����̴�. 
�� ���� N�ٿ� ���ļ� �����̰� ��ġ�� ������ ���ʴ�� �־�����. ������ -10,000���� ũ�ų� ����, 10,000���� �۰ų� ����.
7
1
5
2
10
-99
7
5
���
�� �ٿ� �ϳ��� N�ٿ� ���� �������� ������ ���ؾ��ϴ� ���� ������� ����Ѵ�.
1
1
2
2
2
2
5
*/
//�ð��ʰ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v;
	while (n--) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
		sort(v.begin(), v.end());
		int siz = v.size();
		cout << v[(0 + siz - 1) / 2] << "\n";
	}
}