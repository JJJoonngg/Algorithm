/*
https://www.acmicpc.net/problem/17136
����
���簢�� ����� �� �ټ� ������ �����̰� �ִ�. �������� ũ��� 1��1, 2��2, 3��3, 4��4, 5��5�� �� �ټ� ������ ������, �� ������ �����̴� 5���� ������ �ִ�.
�����̸� ũ�Ⱑ 10��10�� ���� ���� ���̷��� �Ѵ�. ���̴� 1��1 ũ���� ĭ���� �������� ������, ������ ĭ���� 0 �Ǵ� 1�� ���� �ִ�.
1�� ���� ĭ�� ��� �����̷� �������� �Ѵ�. �����̸� ���� ���� ������ ��� ������ �������� �ȵǰ�, ���ĵ� �� �ȴ�. ��, ĭ�� ���� ��ġ�ϰ� �ٿ��� �Ѵ�.
0�� ���� ĭ���� �����̰� ������ �� �ȴ�.

���̰� �־����� ��, 1�� ���� ��� ĭ�� ���̴µ� �ʿ��� �������� �ּ� ������ ���غ���.

�Է�
�� 10���� �ٿ� ������ �� ĭ�� ���� ���� �־�����.

���
��� 1�� ���µ� �ʿ��� �������� �ּ� ������ ����Ѵ�. 1�� ��� ���� ���� �Ұ����� ��쿡�� -1�� ����Ѵ�.
*/
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int paper[6] = { 0,0,0,0,0,0 };
int res = INF;
void dfs(int y, int x, int siz, int ans, vector<vector<int>> MAP) {
	if (ans > res) return;
	//���� ���� �ƴ��� check
	bool check = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (MAP[i][j] == 1) {
				check = true;
				break;
			}
		}
		if (check) break;
	}

	//�Ұ��� �� ����ϰ� �Ѱ��ֱ�
	if (!check) {
		res = min(res, ans - 1);
		if (res == -1) res = 0;
		return;
	}

	//�������� ���� �� ã�� ���߿� �ƴϸ� �׳� return
	for (int i = y; i < y + siz; i++) {
		for (int j = x; j < x + siz; j++) {
			if (i >= 10 || j >= 10 || MAP[i][j] == 0) return;
			MAP[i][j] = 0;
		}
	}

	//���Ӱ� �簢�� �� �� ã��
	int newX, newY;
	bool flag = false;
	for (newX = 0; newX < 10; newX++) {
		for (newY = 0; newY < 10; newY++) {
			if (MAP[newY][newX] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	//ū�� ���� ���� ��Ʈ��ŷ
	for (int siz_ = 5; siz_ >= 1; siz_--) {
		if (paper[siz_] == 5) continue;
		paper[siz_]++;
		dfs(newY, newX, siz_, ans + 1, MAP);
		paper[siz_]--;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> MAP(10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int input; cin >> input;
			MAP[i].push_back(input);
		}
	}
	dfs(0, 0, 0, 0, MAP);
	if (res == INF) res = -1;
	cout << res << "\n";
}