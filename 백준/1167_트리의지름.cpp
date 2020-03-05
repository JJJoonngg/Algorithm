/*
문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

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

알고리즘 분류 : 트리
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAXI 100001
using namespace std;
struct info { int node; int weight; };
vector<info> tree[MAXI];
bool check[MAXI] = { 0, };
int v, res, lastNode;
void dfs(int node, int weight) {
	check[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		int curN = tree[node][i].node;
		int curW = tree[node][i].weight;
		if (!check[curN]) {
			dfs(curN, curW + weight);
			if (curW + weight > res) {
				res = curW + weight;
				lastNode = curN;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v;
	for (int i = 0; i < v; i++) {
		int node; cin >> node;
		while (true) {
			int input, weight;
			cin >> input;
			if (input == -1) break;
			cin >> weight;
			tree[node].push_back({ input, weight });
		}
	}
	dfs(1, 0);
	memset(check, 0, sizeof(check));
	dfs(lastNode, 0);
	cout << res << "\n";
}