/*
order (테이블 번호 n) (주문시간 t): 주문 시간 t에 테이블 n에서 주문 들어옴 (주문이 들어오면 갖고 있는 포스트잇들의 맨 뒤에 새 포스트잇을 추가)
sort: 주문 시간이 빠른 순서대로 정렬
complete n: n번 테이블의 요리 완성. (요리를 완성하는 시점에 해당 테이블에 두 개 이상의 주문이 밀려 있거나 주문이 없는 경우는 존재하지 않음

입력
입력의 첫째 줄에 질의의 수 N과 테이블의 수 M이 주어진다. (1≤N, M≤100)
다음 N줄에 각각의 명령어들이 주어진다.
포스트잇을 정렬할 때 주문 시간이 같다면 테이블 번호가 작은 것을 더 앞에 놓는다. (1 ≤ 주문 시간 ≤ 1,000 , 1 ≤ 테이블 번호 ≤ M)
7 3
order 1 4
order 2 2
order 3 3
sort
complete 3
complete 2
complete 1
출력
각 줄에 각 명령어가 수행된 뒤의 포스트잇들에 적힌 테이블 번호를 출력한다. 아무 포스트잇도 없을 경우 sleep을 출력한다.
1
1 2
1 2 3
2 3 1
2 1
1
sleep
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct info { int num; int time; };
bool comp(info tmp1, info tmp2) {
	if (tmp1.time == tmp2.time) return tmp1.num < tmp2.num;
	else return tmp1.time < tmp2.time;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<info> v;
	while (n--) {
		string input; 
		int number, t;
		cin >> input;
		if (input == "order") {
			cin >> number >> t;
			v.push_back({ number,t });
		}
		else if (input == "sort") sort(v.begin(), v.end(), comp);
		else if (input == "complete") {
			cin >> number;
			vector<info>::iterator it;
			for (it = v.begin(); it != v.end(); it++) {
				if (it->num == number) break;
			}
			v.erase(it);
		}
		if (v.size() == 0) cout << "sleep\n";
		else {
			vector<info>::iterator it;
			for (it = v.begin(); it != v.end(); it++) {
				cout << it->num << " ";
			}
			cout << "\n";
		}
	}

}