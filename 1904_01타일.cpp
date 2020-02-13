#include <bits/stdc++.h>
constexpr auto mod = 15746;
constexpr auto MAXI = 1000001;
using namespace std;
int N, arr[MAXI];
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= N; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
	cout << arr[N] % mod << "\n";
	return 0;
}