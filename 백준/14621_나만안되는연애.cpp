#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXI 1000 + 1
using namespace std;
char arr[MAXI] = { 0, };
vector<pair<int,int>> graph[MAXI];
bool visit[MAXI];
int n, m;
int MST() {
	int res = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visit[now]) continue;
		visit[now] = true;
		res += cost;
		for (auto a : graph[now]) {
			if (!visit[a.second])
				pq.push(make_pair(a.first * (-1), a.second));
		}
	}
	for (int i = 1; i <= n; i++) if (!visit[i]) return -1;
	return res * (-1);
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		char input; cin >> input;
		arr[i] = input;
	}
	for (int i = 0; i < m; i++) {
		int u, v, d; cin >> u >> v >> d;
		if (arr[u] == arr[v]) continue;
		graph[u].push_back(make_pair(d,v));
		graph[v].push_back(make_pair(d,u));
	}
	cout << MST() << "\n";
}