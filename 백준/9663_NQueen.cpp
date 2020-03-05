/*
����
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.
N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N < 15)
8

���
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�
92
�˰��� �з� : ��Ʈ��ŷ
*/
#include <bits/stdc++.h>
#define MAXI 32
using namespace std;
int n;
bool row[MAXI];
bool positiveDiagonal[MAXI];
bool negativeDiagonal[MAXI];
int res = 0;
void dfs(int col) {
	if (col == n) {
		res++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!row[i] && !positiveDiagonal[col + i] && !negativeDiagonal[n + col - i]) {
				row[i] = positiveDiagonal[col + i] = negativeDiagonal[n + col - i] = true;
				dfs(col + 1);
				row[i] = positiveDiagonal[col + i] = negativeDiagonal[n + col - i] = false;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs(0);
	cout << res << "\n";
}