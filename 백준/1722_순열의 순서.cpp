/*
https://www.acmicpc.net/problem/1722
����
1���� N������ ���� ���Ƿ� �迭�� ������ �� N! = N��(N-1)������2��1 ������ �ִ�.
������ ������ ������ �� �� �ִ�. ���� ���  N=3�� ��� {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}�� ������ ������ �� �ִ�. 
ù ��° ���� ���� ���� �����󿡼� �ռ���, ù ��° ���� ������ �� ��° ���� ���� ����, �� ��° ���� ������ �� ��° ���� ���� ���̡�.
N�� �־�����, �Ʒ��� �� �ҹ��� �߿� �ϳ��� Ǯ��� �Ѵ�. k�� �־����� k��° ������ ���ϰ�, 
������ ������ �־����� �� ������ �� ��° ���������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1��N��20)�� �־�����. ��° ���� ù ��° ���� �ҹ��� ��ȣ�̴�. 1�� ��� k(1��k��N!)�� �Է¹ް�, 
2�� ��� ������ ������ ��Ÿ���� N���� ���� �Է¹޴´�. N���� ������ 1���� N������ ������ �� ������ ��Ÿ����.
4
1 3
4
2 1 3 2 4
���
k��° ������ ��Ÿ���� N���� ���� ����ϰų�, �� ��° ���������� ����ϸ� �ȴ�
1 3 2 4
3

�˰��� �з� :����, ����, ����
*/
#include <bits/stdc++.h>
using namespace std;
int n, k;
bool check[21];
long long factorial[21], res = 0;
vector<int> v;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	v.resize(n);
	factorial[0] = 1;
	for (int i = 1; i < 21; i++) factorial[i] = factorial[i - 1] * i;
	if (k == 1) {
		long long input;
		cin >> input;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[j]) continue;
				if (factorial[n - 1 - i] < input)
					input -= factorial[n - 1 - i];
				else {
					v[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) cout << v[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) cin >> v[i];
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) 
				if (!check[j]) res += factorial[n - 1 - i];
			check[v[i]] = true;
		}
		cout << res + 1 << "\n";
	}
}