/*
입력입력
입력의 첫 줄에는 CTP의 회원수 N(1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 대회에 참가한 팀의 수 M(1 ≤ M ≤ 1,000)과 팀을 구성하는데 필요한 팀원의 수 K(1 ≤ K ≤ 10)가 주어진다.
셋째 줄에는 각각의 CTP 회원들이 가지고 있는 펜의 수 A(0 ≤ A ≤ 100)가 공백을 구분으로 주어진다.
7
36 3
9 70 15 13 19 20 11
출력
정은이가 최소한의 회원들에게 빌리려고 할 때, 빌린 회원의 수를 출력한다.
만약 펜이 부족한 경우 "STRESS"(따옴표는 제외)를 출력한다.

3
*/
#include <iostream>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	int res = m * k, cnt = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		pq.push(input);
	}
	while (!pq.empty()) {
		res -= pq.top();
		pq.pop();
		cnt++;
		if (res <= 0) break;
	}
	if (res > 0 && pq.empty()) cout << "STRESS\n";
	else cout << cnt << "\n";

}