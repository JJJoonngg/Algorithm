/*
https://www.acmicpc.net/problem/2581
����
�ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

���� ��� M=60, N=100�� ��� 60�̻� 100������ �ڿ��� �� �Ҽ��� 61, 67, 71, 73, 79, 83, 89, 97 �� 8���� �����Ƿ�, �̵� �Ҽ��� ���� 620�̰�, �ּڰ��� 61�� �ȴ�.

�Է�
�Է��� ù° �ٿ� M��, ��° �ٿ� N�� �־�����.
M�� N�� 10,000������ �ڿ����̸�, M�� N���� �۰ų� ����.
60
100

64
65
���
M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ã�� ù° �ٿ� �� ����, ��° �ٿ� �� �� �ּڰ��� ����Ѵ�.

��, M�̻� N������ �ڿ��� �� �Ҽ��� ���� ���� ù° �ٿ� -1�� ����Ѵ�.
620
61

-1
*/
#include <iostream>
#include <math.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m, n, res = 0, ans = 0; cin >> m >> n;
	int arr[10001] = { 0, };
	arr[1] = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i]) continue;
		for (int j = i + i; j <= n; j += i)
			arr[j] = true;
	}

	for (int i = m; i <= n; i++)
		if (!arr[i]) {
			res += i;
			if (ans == 0) ans = i;
		}
	if (!res) cout << "-1\n";
	else cout << res << "\n" << ans << "\n";
}