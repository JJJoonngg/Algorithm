/*
https://www.acmicpc.net/problem/12783
����
�־��� ���� ī��� ��Ģ����, ��ȣ ���� �����Ͽ� ���ϴ� ���� ����� ������ �ִ�.
�� ������ �����ϴ� �������� �̹� IT�������� MT���� �� ������ �Ϸ��� ī�带 ì���.
�׷��� �Ǽ��� ī����� �� ì���� �� �ߴ�. ������ ī��� ���� ���ϱ� ī�常 ì���, ����ī��� 0���� 9���� ī�� �� N���� ������ ī�常 ì���.
�׷��� ���� ������ ������ ���� �������� �����ϱ�� �Ͽ���.
���� ������ ������ ���ڸ� �־��� ����ī��� ����ī�带 �����Ͽ� ����� �����̴�.
�� ������ ����ī���� ������ ���� ���� ����ϴ� ���� �¸��ϰ� �ȴ�.
������ ����ī���� ������ �־����� ��, ����ī�带 ���� ���� ����Ͽ� ������ �¸��� �� �ֵ��� ����.
ī��� �� �������� ����� ���� ������ ������ ���� ����.

���� ���, ������ ����ī���� ������ 2,3,6 �� ��, 64�� 32 x 2 �� ���ϱ� 1���� ����Ͽ� ���� �� �ְ� �̴� ����ī�带 ���� ���� ����� ���̴�.

�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T(1 �� T �� 50)�� �־�����.
�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ���� ī���� ������ ���� N(1 �� N �� 10)�� N���� ���� ī���� ������ ������ �������� �־�����.
�� �׽�Ʈ ���̽��� �� ��° �ٿ��� ������ �� M(1 �� M �� 20)�� �־�����.
���� M���� �ٿ��� ������� �ϴ� �ڿ��� K�� �־�����.(K �� 1,000,000)
2
3 2 3 6
3
64
5
7
4 1 2 3 4
2
31
16
���
�� ���Ǹ��� ����ī���� �ּ��� ������ ����Ѵ�. ���� ���� �� ���� ��쿡�� -1�� ����Ѵ�.
1
-1
-1
0
1
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 1e9
#define MAXI 1000000 + 1
using namespace std;
int num[MAXI];
int dp[MAXI];
int t, n, m, res;

void checkMadeByNoneMultiply(int x) {
	if (x == 0 && num[0] == true) { dp[x] = 0; return; }
	bool flag = true;
	int tmp = x;
	while (tmp > 0) {
		if (num[tmp % 10] == false) {
			flag = false;
			break;
		}
		tmp /= 10;
	}
	if (flag) dp[x] = 0;
}
int function(int input) {
	if (dp[input] != -1) return dp[input];
	
	int ans = INF;
	for (int i = 2; i <= sqrt(input); i++)
		if (input%i == 0)
			ans = min(ans, function(i) + function(input / i) + 1);
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(num, false, sizeof(num));
		cin >> n;
		while (n--) {
			int tmp; cin >> tmp;
			num[tmp] = true;
		}
		cin >> m;
		while (m--) {
			int input; cin >> input;
			for (int i = 0; i <= input; i++)
				checkMadeByNoneMultiply(i);

			res = INF;
			res = function(input);
			if (res == INF) res = -1;
			cout << res << "\n";
		}
	}
}