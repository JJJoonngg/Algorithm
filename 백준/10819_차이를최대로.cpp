/*
https://www.acmicpc.net/problem/10819
����
N���� ������ �̷���� �迭 A�� �־�����.
�̶�, �迭�� ����ִ� ������ ������ ������ �ٲ㼭 ���� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

�Է�
ù° �ٿ� N (3 �� N �� 8)�� �־�����. ��° �ٿ��� �迭 A�� ����ִ� ������ �־�����.
�迭�� ����ִ� ������ -100���� ũ�ų� ����, 100���� �۰ų� ����.
6
20 1 15 4 10 8

���
ù° �ٿ� �迭�� ����ִ� ���� ������ ������ �ٲ㼭 ���� �� �ִ� ���� �ִ��� ����Ѵ�.
62

���Ʈ ����,  DFS
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, res = 0;
vector<int> a, b;
bool visit[9];
void cal() {
	int tmp = 0;
	for (int i = 0; i < n - 1; i++)
		tmp += abs(b[i] - b[i + 1]);
	res = max(res, tmp);
}
void dfs() {
	if (b.size() == n) cal();
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			b.push_back(a[i]);
			dfs();
			visit[i] = false;
			b.pop_back();
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n; a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	dfs();
	cout << res << "\n";
}