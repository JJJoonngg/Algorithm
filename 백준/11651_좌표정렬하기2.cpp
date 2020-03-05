/*
https://www.acmicpc.net/problem/11651
문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.
(-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
5
0 4
1 2
1 -1
2 2
3 3
출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
1 -1
1 2
2 2
3 3
0 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct xy { int x; int y; };
vector<xy> v;
bool comp(xy tmp1, xy tmp2) {
	if (tmp1.y == tmp2.y) return tmp1.x < tmp2.x;
	else return tmp1.y < tmp2.y;
}
int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) cout << v[i].x << " " << v[i].y << "\n";
}