/*
https://www.acmicpc.net/problem/10974
����
N�� �־����� ��, 1���� N������ ���� �̷���� ������ ���������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 8)�� �־�����.
3
���
ù° �ٺ��� N!���� �ٿ� ���ļ� ��� ������ ���������� ����Ѵ�.
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
bool visit[9];
void dfs() {
	if (v.size() == n) {
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true; v.push_back(i);
			dfs();
			visit[i] = false; v.pop_back();
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs();
}