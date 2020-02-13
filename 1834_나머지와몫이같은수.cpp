#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, res = 0;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (ll i = 1; i < n; i++)
		res += (n - i) * n + (n - i);
	cout << res << "\n";
	return 0;
}