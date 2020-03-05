/*
https://www.acmicpc.net/problem/1655
입력
첫째 줄에는 수빈이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다. 
그 다음 N줄에 걸쳐서 수빈이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.
7
1
5
2
10
-99
7
5
출력
한 줄에 하나씩 N줄에 걸쳐 수빈이의 동생이 말해야하는 수를 순서대로 출력한다.
1
1
2
2
2
2
5
*/
//시간초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v;
	while (n--) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
		sort(v.begin(), v.end());
		int siz = v.size();
		cout << v[(0 + siz - 1) / 2] << "\n";
	}
}