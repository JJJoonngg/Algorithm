#include <bits/stdc++.h>
constexpr double INF = DBL_MAX;
constexpr auto MAXI = 21;
using namespace std;
double res = INF, n, t, x, y;
struct info { double x, y; };
bool check[MAXI];
vector<info> v;
void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			if (check[i]) x -= v[i].x, y -= v[i].y;
			else x += v[i].x, y += v[i].y;
		}
		res = min(res, sqrt(pow(x, 2) + pow(y, 2)));
		return;
	}
	if (idx == n) return;
	dfs(idx + 1, cnt);
	check[idx] = true;
	dfs(idx + 1, cnt + 1);
	check[idx] = false;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		v.clear();
		res = INF;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x,y });
		}
		dfs(0, 0);
		cout << fixed;
		cout.precision(12);
		cout << res << "\n";
	}
	return 0;
}