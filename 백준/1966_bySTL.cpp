#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int test;
	cin >> test; 
	
	while (test--) {
		int N, M;
		cin >> N >> M;
		priority_queue<int> pq;
		queue<pair<int, bool>> q;
		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			pq.push(data);
			if (i == M) q.push(make_pair(data,true));
			else q.push(make_pair(data, false));
		}
		int cnt = 0;
		while (!q.empty()) {
			if (pq.top() == q.front().first) {
				if (q.front().second) {
					cnt++;
					break;
				}
				q.pop();
				pq.pop();
				cnt++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		cout << cnt << endl;
	}

	return 0;
}