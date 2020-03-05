#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, tmp, res, siz = 0;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	tmp = n;
	while (tmp > 0) {
		tmp /= 10;
		siz++;
	}
	int a = 1;
	for (int i = 1; i < siz; i++) {
		res += i * 9 * a;
		a *= 10;
	}
	res += (n - a + 1) * siz;
	cout << res << "\n";
	return 0;
}