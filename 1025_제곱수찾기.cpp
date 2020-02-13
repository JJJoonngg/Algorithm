#include <bits/stdc++.h>
constexpr auto MAXI = 10;
using namespace std;
int N, M, arr[MAXI][MAXI], res = -1, cur = 0;
char input;
bool checkRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }
bool judgeSquare(int x) {
	int tmp = x % 10;
	if (tmp == 2 || tmp == 3 || tmp == 7 || tmp == 8) return false;
	int tmp2 = (int)(sqrt((double)x) + 0.5);
	return tmp2 * tmp2 == x;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			arr[i][j] = input - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = -N; k < N; k++) {
				for (int l = -M; l < M; l++) {
					if (k == 0 && l == 0) continue;
					int x = i, y = j;
					cur = 0;
					while (true) {
						if (!checkRange(x, y)) break;
						cur *= 10, cur += arr[x][y];
						if (judgeSquare(cur)) res = max(res, cur);
						x += k, y += l;
					}

				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}