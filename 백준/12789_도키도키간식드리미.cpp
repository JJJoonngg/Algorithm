/*
입력
입력의 첫째 줄에는 현재 승환이의 앞에 서 있는 학생들의 수 N(1 ≤ N ≤ 1,000,자연수)이 주어진다.
다음 줄에는 승환이 앞에 서있는 모든 학생들의 번호표(1,2,...,N) 순서가 앞에서부터 뒤 순서로 주어진다.
5
5 4 1 3 2

출력
승환이가 무사히 간식을 받을 수 있으면 "Nice"(따옴표는 제외)를 출력하고 그렇지 않다면 "Sad"(따옴표는 제외)를 출력한다.
Nice
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	stack<int> s;
	queue<int> q;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	int start = 1;

	for (int i = 0; i < N; i++) {
		if (q.front() == start) {
			q.pop();
			start++;
		}
		else {
			if (!s.empty()) {
				if (s.top() == start) {
					s.pop();
					start++;
					i--;
					continue;
				}
			}
			s.push(q.front());
			q.pop();
		}
	}


	while (!s.empty()) {
		if (start == s.top()) {
			s.pop();
			start++;
		}
		else break;
	}
	if (s.empty()) cout << "Nice" << endl;
	else cout << "Sad" << endl;

	return 0;
}