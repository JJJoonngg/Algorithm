/*
����
���� 1, 2, 3���θ� �̷������ ������ �ִ�. ������ ������ ������ �� ���� �κ� ������ ������ ���� ������,
�� ������ ���� �����̶�� �θ���. �׷��� ���� ������ ���� �����̴�.
������ ���� ������ ���̴�.

33
32121323
123123213
������ ���� ������ ���̴�.
2
32
32123
1232123
���̰� N�� ���� �������� N�ڸ��� ������ ���� ���� ���� ���� ���� ��Ÿ���� ������ ���ϴ� ���α׷��� �ۼ��϶�.
���� ���, 1213121�� 2123212�� ��� ���� ���������� �� �߿��� ���� ���� ��Ÿ���� ������ 1213121�̴�.

�Է�
�Է��� ���� N�ϳ��� �̷������. N�� 1 �̻� 80 �����̴�.
7
���
ù ��° �ٿ� 1, 2, 3���θ� �̷���� �ִ� ���̰� N�� ���� ������ �߿��� ���� ���� ���� ��Ÿ���� ������ ����Ѵ�.
������ �̷�� 1, 2, 3�� ���̿��� ��ĭ�� ���� �ʴ´�.
1213121
�˰��� �з� : ��Ʈ��ŷ
*/
#include <bits/stdc++.h>
#define MAXI 80 + 1
using namespace std;
int N;
bool flag = false;
bool check(string s) {
	reverse(s.begin(), s.end());
	for (int i = 1; i <= s.length() / 2; i++) {
		if (s.substr(0, i) == s.substr(i, i)) return false;
	}
	return true;
}
void dfs(int len, string s) {
	if (flag) return;
	if (N == len) {
		flag = true;
		cout << s <<"\n";
	}
	else {
		for (int i = 1; i <= 3; i++)
			if (check(s + to_string(i)))
				dfs(len + 1, s + to_string(i));
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dfs(1, "1");
}