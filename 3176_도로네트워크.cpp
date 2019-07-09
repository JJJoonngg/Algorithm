/*
https://www.acmicpc.net/problem/3176
문제
N개의 도시와 그 도시를 연결하는 N-1개의 도로로 이루어진 도로 네트워크가 있다.
모든 도시의 쌍에는 그 도시를 연결하는 유일한 경로가 있고, 각 도로의 길이는 입력으로 주어진다.
총 K개의 도시 쌍이 주어진다. 이때, 두 도시를 연결하는 경로 상에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (2 ≤ N ≤ 100,000)
다음 N-1개 줄에는 도로를 나타내는 세 정수 A, B, C가 주어진다. A와 B사이에 길이가 C인 도로가 있다는 뜻이다. 도로의 길이는 1,000,000보다 작거나 같은 양의 정수이다.
다음 줄에는 K가 주어진다. (1 ≤ K ≤ 100,000)
다음 K개 줄에는 서로 다른 두 자연수 D와 E가 주어진다. D와 E를 연결하는 경로에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구해서 출력하면 된다.
5
2 3 100
4 3 200
1 5 150
1 3 50
3
2 4
3 5
1 2

출력
총 K개 줄에 D와 E를 연결하는 경로에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 출력한다.
100 200
50 150
50 100

알고리즘 분류 : LCA
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXI 100000 + 1
#define INF 1e9
#define NAV -1
using namespace std;
struct info { int num; int cost; };
int n, k;
vector<info> graph[MAXI];
int parent[MAXI][21], depth[MAXI];
int maxANS[MAXI][21], minANS[MAXI][21];



//LCA를 하기 위한 전처리 함수로 tree를 생성
void dfs(int cur, int p, int value) {
	depth[cur] = depth[p] + 1;
	parent[cur][0] = p;
	minANS[cur][0] = value;
	maxANS[cur][0] = value;

	for (int i = 1; i <= 20; i++)
		parent[cur][i] = parent[parent[cur][i - 1]][i - 1];

	for (auto next : graph[cur]) {
		if (next.num != p)
			dfs(next.num, cur, next.cost);
	}
}

//루트 노드로 부터 각 노드로 오는 경로중 최솟값과 최댓값 저장 전처리
void prevCalculation() {
	for (int _parent = 1; _parent <= 20; _parent++) {
		for (int _cur = 1; _cur <= n; _cur++) {
			minANS[_cur][_parent] = min(minANS[_cur][_parent - 1], minANS[parent[_cur][_parent - 1]][_parent - 1]);
			maxANS[_cur][_parent] = max(maxANS[_cur][_parent - 1], maxANS[parent[_cur][_parent - 1]][_parent - 1]);
		}
	}
}

void lca(int a, int b) {
	int minRes = INF;
	int maxRes = NAV;
	if (depth[a] != depth[b]) {
		//depth가 높은 쪽을 기준으로 depth가 낮은 곳까지 반복
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = 20; i >= 0; i--) {
			if (depth[b] <= depth[parent[a][i]]) {
				//min 과 max 값 갱신 필요
				//a가 parent 로 올라감
				minRes = min(minRes, minANS[a][i]);
				maxRes = max(maxRes, maxANS[a][i]);
				a = parent[a][i];
			}
		}
	}

	//lca 계산용
	int tmp = b;

	//depth는 동일하지만 lca로 못갈 경우
	//서로의 조상노드를 타고 올라가며 lca까지 반복
	//역시나 min, max 값 갱신 필요
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				minRes = min(minRes, min(minANS[a][i], minANS[b][i]));
				maxRes = max(maxRes, max(maxANS[a][i], maxANS[b][i]));
				a = parent[a][i];
				b = parent[b][i];
			}
			//parent로 찾아 올라감
			tmp = parent[b][i];
		}
	}
	//lca 바로 아래 값들만 min, max 설정 되어있으므로
	//a와 lca, b와 lca 사이의 값들도 갱신 필요
	if (b != tmp) {
		minRes = min(minRes, min(minANS[a][0], minANS[b][0]));
		maxRes = max(maxRes, max(maxANS[a][0], maxANS[b][0]));
	}
	cout << minRes << " " << maxRes << "\n";
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	depth[0] = -1;
	dfs(1, 0, 0);
	prevCalculation();
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		lca(x, y);
	}
}

