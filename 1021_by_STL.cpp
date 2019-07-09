#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m, cnt = 0;

	deque<int> dq;

	cin >> n >> m;
	int* arr = new int[m];

	for (int i = 1; i <= n; i++) { dq.push_back(i); }

	for (int i = 0; i < m; i++) { cin >> arr[i]; }

	for (int i = 0; i < m; i++) {
		while (true) {
			int cur = 0;
			if (arr[i] == dq.front()) {
				dq.erase(dq.begin());
				break;
			}
			for (int j = 0; j < dq.size(); j++) {
				if (arr[i] == dq[j])
					cur = j;
			}
			int tmp_left = cur;
			int tmp_right = dq.size() - cur - 1;

			if (tmp_left <= tmp_right) {
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				cnt++;
			}
			else if (tmp_left > tmp_right) {
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	delete[] arr;
	return 0;
}
