/*
https://www.acmicpc.net/problem/1167
입력
트리가 입력으로 주어진다. 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2≤V≤100,000)
둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. (정점 번호는 1부터 V까지 매겨져 있다고 생각한다)

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 
하나는 정점번호, 다른 하나는 그 정점까지의 거리이다.
예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고,
정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 
주어지는 거리는 모두 10,000 이하의 자연수이다.
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1
출력
첫째 줄에 트리의 지름을 출력한다.
11
*/
#include <iostream>
#include <vector>
#include <string.h>
#define MAXI 100001
using namespace std;
struct info { int node; int value; };
bool check[MAXI];
vector<info> tree[MAXI];
int n, res = 0 , newRoot;
void dfs(int cur, int val) {
	check[cur] = true;
	for (auto a : tree[cur]) {
		if (!check[a.node]) {
			dfs(a.node, a.value + val);
			if (res < a.value + val) {
				res = a.value + val;
				newRoot = a.node;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		int node; cin >> node;
		while(true) {
			int a, b; 
			cin >> a;
			if (a == -1) break;
			cin >> b;
			tree[node].push_back({ a,b });
		}
	}
	dfs(1, 0);
	memset(check, false, sizeof(check));
	dfs(newRoot, 0);
	cout << res << "\n";
}