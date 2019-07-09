/*
입력
파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 둘째 줄부터 n번째 줄까지 각 간선에 대한 정보가 들어온다. 
간선에 대한 정보는 세 개의 정수로 이루어져 있다. 첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고,
두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고,
부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 
루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
출력
첫째 줄에 트리의 지름을 출력한다.
45
*/
#include <iostream>
#include <vector>
#include <string.h>
#define MAXI 10000+1
using namespace std;
struct info { int node; int value; };
vector<info> tree[MAXI];
bool check[MAXI];
int res = 0, newRoot = 0;
void search(int node, int val){
	check[node] = true;
	for (auto a : tree[node]) {
		if (!check[a.node]) {
			int tmp = a.value + val;
			search(a.node, tmp);
			if (tmp > res) {
				res = tmp;
				newRoot = a.node;
			}
		}
	}
	/*for (int i = 0; i < tree[node].size(); i++) {
		int tmpN = tree[node][i].node;
		int tmpV = tree[node][i].value;
		if (!check[tmpN]) {
			search(tmpN, tmpV + val);
			if (tmpV + val > res) {
				res = tmpV + val;
				newRoot = tmpN;
			}
		}
	}*/
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while(n--) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	search(1, 0);
	memset(check, false, sizeof(check));
	search(newRoot, 0);
	cout << res << "\n";
}