#include <bits/stdc++.h>
constexpr auto MAXI = 31;
using namespace std;
int dp[MAXI], res = 0, n;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	dp[0] = 1, dp[1] = 0, dp[2] = 3;
	if (n % 2 == 0) {
		for (int i = 4; i <= n; i += 2) {
			for (int j = 2; j <= i; j += 2) {
				int tmp = j == 2 ? 3 : 2;
				dp[i] += tmp * dp[i - j];
			}
		}
		cout << dp[n] << "\n";
		return 0;
	}
	cout << "0\n";
	return 0;
}