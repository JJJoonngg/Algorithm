#include <bits/stdc++.h>
using namespace std;
int N, r, c, res = 0;
void func(int x, int y, int cur) {
	if (x == r && y == c) {
		cout << res << "\n";
		return;
	}

	if (r < x + cur && x <= r && c < y + cur && y <= c) {
		func(x, y, cur / 2); //1��и�
		func(x, y + cur / 2, cur / 2); //2��и�
		func(x + cur / 2, y, cur / 2); //3��и�
		func(x + cur / 2, y + cur / 2, cur / 2); //4��и�
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