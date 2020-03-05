#include <bits/stdc++.h>
using namespace std;
int N, L;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> L;
	for (int i = L; i <= 100; i++) {
		int tmp = N - i * (i - 1) / 2;
		if (!(tmp % i) && tmp >= 0) {
			tmp /= i;
			for (int j = 0; j < i; j++) {
				cout << tmp + j << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}