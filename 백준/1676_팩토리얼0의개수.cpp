#include <bits/stdc++.h>
using namespace std;
int n, res = 0;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) res++;
		if (i % 25 == 0) res++;
		if (i % 125 == 0) res++;
	}
	cout << res<< "\n";
	return 0;
}