#include <bits/stdc++.h>
using namespace std;
long long A, B;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> A >> B;
	if (A != B) {
		A > B ? cout << ">\n" : cout << "<\n";
		return 0;
	}
	cout << "==\n";
	return 0;
}