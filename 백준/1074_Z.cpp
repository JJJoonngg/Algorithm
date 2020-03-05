#include <bits/stdc++.h>
using namespace std;
int N, r, c, res = 0;
void func(int x, int y, int cur) {
	if (x == r && y == c) {
		cout << res << "\n";
		return;
	}

	if (r < x + cur && x <= r && c < y + cur && y <= c) {
		func(x, y, cur / 2); //1사분면
		func(x, y + cur / 2, cur / 2); //2사분면
		func(x + cur / 2, y, cur / 2); //3사분면
		func(x + cur / 2, y + cur / 2, cur / 2); //4사분면
	}
	else res += cur * cur;;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> r >> c;
	func(0, 0, pow(2, N));
	return 0;
}