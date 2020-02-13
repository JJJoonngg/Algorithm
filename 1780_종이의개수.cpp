#include <bits/stdc++.h>
constexpr auto MAXI = 2200;
using namespace std;
int n, arr[MAXI][MAXI], res[3];
bool check[3];
void func(int r, int c, int siz) {
	if (siz == 1) {
		res[arr[r][c] + 1]++;
		return;
	}
	memset(check, true, sizeof(check));
	for (int i = r; i < r + siz; i++) {
		for (int j = c; j < c + siz; j++) {
			if (arr[i][j] == -1) check[1] = check[2] = false;
			else if (arr[i][j] == 0)check[0] = check[2] = false;
			else if (arr[i][j] == 1)check[0] = check[1] = false;
		}
	}
	if (check[0]) res[0]++;
	else if (check[1]) res[1]++;
	else if (check[2]) res[2]++;
	else {
		siz /= 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				func(r + siz * i, c + siz * j, siz);
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	func(0, 0, n);

	for (int i = 0; i < 3; i++) cout << res[i] << "\n";
	return 0;
}