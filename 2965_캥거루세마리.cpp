#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> A >> B >> C;
	cout << max(abs(A - B), abs(B - C)) - 1 << "\n";
	return 0;
}