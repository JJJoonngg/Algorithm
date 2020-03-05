/*

문제
트리(tree)는 사이클이 없는 무방향 그래프이다. 
트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다. 
트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우가 있을 것이다. 
이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.
이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다.
정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.
입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 
아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.

입력
파일의 첫 번째 줄은 노드의 개수 n (1≤n ≤10000)이다. 
둘째 줄부터 n 번째 줄까지 각 간선에 대한 정보가 들어온다. 
간선에 대한 정보는 세 개의 정수로 이루어져 있다. 
첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 
세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 
부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 루트 노드의 번호는 항상 1이라고 가정하며,
간선의 가중치는 100보다 크지 않은 양의 정수이다.
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

풀이 방법 :  root로 부터 가장 멀리 떨어진 노드를 새롭게 root 로 설정하고 
새롭게 설정된 root 로부터 가장 멀리 떨어진 노드까지의 길이가 트리의 지름이 된다.
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
//vector를 배열로 선언하고, 벡터 내에 연결된 노드와 간선 가중치의 값을 저장하기위해 pair로 두가지 변수 저장
vector<pair<int, int>> tree[10001]; 
//DFS를 하면서 한번 지나친 노드에 대해 중복을 피하기 위한 bool타입 변수 선언
bool check[10001];
int n;
int max_distance = 0, max_node = 0;
int diameter = 0;

void search(int start, int next) {
	check[start] = true;
	for (int i = 0; i < tree[start].size(); i++) {
		//탐색하지 않은 노드들을 대상으로 찾아가며 가장 거리가 먼 노드를 찾는다.
		if (!check[tree[start][i].first]) {

			search(tree[start][i].first, tree[start][i].second + next);
			//만약 탐색을 하다가 가지고 있던 정보보다 거리가 먼 노드를 찾으면 정보를 새롭게 갱신한다.
			if (tree[start][i].second + next > max_distance) {
				max_distance = tree[start][i].second + next;
				max_node = tree[start][i].first;
			}
		}
	}
}

int main() {
	cin >> n;
	//입력을 받음과 동시에 tree변수에 해당 정보들을 저장한다.
	for (int i = 1; i < n; i++) {
		int parent, child, value;
		cin >> parent >> child >> value;
		tree[parent].push_back(make_pair(child, value));
		tree[child].push_back(make_pair(parent, value));
	}
	
	//루트 노드로 부터 가장 멀리 떨어진 노드를 찾는 탐색 시작
	search(1, 0);

	//가장 멀리 떨어진 노드를 찾고, 바뀐check 배열을 다시 초기화.
	memset(check, 0, sizeof(check));
	
	//가장 멀리 떨어진 노드를 루트노드로 삼고 DFS 한 번 더 시작.
	search(max_node, 0);
	
	//두 노드 사이의 거리를 저장 및 출력
	diameter = max_distance;
	cout << diameter << endl;

	return 0;
}
