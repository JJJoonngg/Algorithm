/*
https://www.acmicpc.net/problem/10451
�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�� N (2 �� N �� 1,000)�� �־�����.
��° �ٿ��� ������ �־�����, �� ������ �������� ���еǾ� �ִ�.
2
8
3 2 7 8 1 4 5 6
10
2 1 3 4 5 6 7 9 10 8
���
�� �׽�Ʈ ���̽�����, �Է����� �־��� ������ �����ϴ� ���� ����Ŭ�� ������ ����Ѵ�.
3
7
*/
#include <iostream>
#include <vector>
#define MAXI 1000 + 1
using namespace std;
vector<int> v[MAXI];
bool visit[MAXI];
int res;
void dfs(int cur) {
	visit[cur] = true;
	for (auto a : v[cur])
		if (!visit[a])
			dfs(a);
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < MAXI; i++) v[i].clear(), visit[i] = false;
		res = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			int input; cin >> input;
			v[i].push_back(input);
		}
		for (int i = 1; i <= n; i++) if (!visit[i]) dfs(i), res++;
		cout << res << "\n";
	}
}