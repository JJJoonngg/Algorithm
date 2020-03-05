/*
https://www.acmicpc.net/problem/5567
문제
상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 친구의 친구를 초대하기로 했다. 
상근이의 동기는 모두 N명이고, 이 학생들의 학번은 모두 1부터 N까지이다. 상근이의 학번은 1이다.

상근이는 동기들의 친구 관계를 모두 조사한 리스트를 가지고 있다. 이 리스트를 바탕으로 결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이의 동기의 수 n (2 ≤ n ≤ 500)이 주어진다. 둘째 줄에는 리스트의 길이 m (1 ≤ m ≤ 10000)이 주어진다. 
다음 줄부터 m개 줄에는 친구 관계 ai bi가 주어진다. (1 ≤ ai < bi ≤ n) ai와 bi가 친구라는 뜻이며, bi와 ai도 친구관계이다.
6
5
1 2
1 3
3 4
2 3
4 5
출력
첫째 줄에 상근이의 결혼식에 초대하는 동기의 수를 출력한다.
3
힌트
2와 3은 상근이의 친구이다. 또, 3과 4는 친구이기 때문에, 4는 상근이의 친구의 친구이다. 5와 6은 친구도 아니고, 친구의 친구도 아니다.
따라서 2,3,4 3명의 친구를 결혼식에 초대한다.
*/
#include <iostream>
#include <vector>
#define MAXI 500 + 1
using namespace std;
int n, m;
int visit[MAXI] = { 0, }, res[MAXI] = { 0, };
vector<int> v[MAXI];
void dfs(int from) {
	for (auto next : v[from]) 
		res[next] = true;
	
	if (from == 1) 
		for (auto next : v[from]) 
			dfs(next);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	int ans = 0;
	for (int i = 2; i <= n; i++) if (res[i]) ans++;
	cout << ans << "\n";
}