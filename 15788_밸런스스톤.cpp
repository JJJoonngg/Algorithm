/*
�Է�
�Է��� ù° �ٿ� ���� ũ�� N(2 �� N �� 500)�� �־�����. ���� N�ٿ� �� ����� �� k�� N���� �־�����.
(1 �� k �� 1,000,000,000�� �ڿ���), ����ִ� ����� �� 0���� �־����� ������ �����ϴ� �� M�� ������ �� ������ �ڿ��� ���� �ǵ��� �־�����.

���
������ ������ �����ϴ� �� M�� ����Ѵ�.
�Է�
3
6 1 8
7 5 3
2 0 4

2
1 0
2 1
���
9
-1
*/
#include <iostream>
using namespace std;
int n, inputX = 0, inputY = 0;
long long arr[501][501] = { 0, };
long long m, sum = 0, mSum = 0, diagonalA = 0, diagonalB = 0;
long long sumRow(int x) {
	long long tmp = 0;
	for (int i = 0; i < n; i++)
		tmp += arr[x][i];
	return tmp;
}
long long sumCol(int x) {
	long long tmp = 0;
	for (int i = 0; i < n; i++)
		tmp += arr[i][x];
	return tmp;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (!arr[i][j]) {
				inputX = i, inputY = j;
			}
		}
	}
	mSum = sumRow(inputX);
	if (inputX != 1)  sum = sumRow(1);
	else sum = sumRow(0);
	
	m = sum - mSum;
	arr[inputX][inputY] = m;

	if (m < 1) {
		m = -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (sum != sumRow(i) || sum != sumCol(i)) {
				m = -1;
				break;
			}
			diagonalA += arr[i][i];
			diagonalB += arr[i][n - i - 1];
		}
		if (diagonalA != sum || diagonalB != sum)
			m = -1;
	}
	cout << m << "\n";
}