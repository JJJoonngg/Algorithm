/*
https://www.acmicpc.net/problem/2170
문제
매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다. 
선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.

이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 
선이 여러 번 그려진 곳은 한 번씩만 계산한다.

입력
첫째 줄에 선을 그은 횟수 N(1≤N≤1,000,000)이 주어진다. 다음 N개의 줄에는 선을 그을 때 선택한 두 점이 주어진다. 
선택한 지점은 -1,000,000,000 이상 1,000,000,000 이하의 정수이다.
4
1 3
2 5
3 5
6 7
출력
첫째 줄에 그은 선의 총 길이를 출력한다.
5
*/
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
struct info { int start, end; };
bool comp(info tmp1, info tmp2) { 
	if(tmp1.start != tmp2.start) return tmp1.start < tmp2.start; 
	else return tmp1.end < tmp2.end;
}
vector<info> v;
int s, e, res = 0;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(), comp);
	s = e = -INF;
	for (int i = 0; i < v.size(); i++) {
		if (e < v[i].start) {
			res += e - s;
			s = v[i].start;
			e = v[i].end;
		}
		else e = max(e, v[i].end);
	}
	res += e - s;
	cout << res << "\n";
}