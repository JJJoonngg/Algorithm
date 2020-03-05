/*
입력
입력의 첫째 줄에 맵의 크기 N(2 ≤ N ≤ 500)이 주어진다. 다음 N줄에 각 블록의 수 k가 N개가 주어진다.
(1 ≤ k ≤ 1,000,000,000의 자연수), 비어있는 블록은 수 0으로 주어지며 조건을 만족하는 수 M이 존재할 시 무조건 자연수 값이 되도록 주어진다.

출력
퍼즐의 조건을 만족하는 수 M을 출력한다.
입력
3
6 1 8
7 5 3
2 0 4

2
1 0
2 1
출력
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