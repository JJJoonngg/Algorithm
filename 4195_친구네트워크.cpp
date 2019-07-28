/*
문제
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 
우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.
어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 
이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다.
친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty
출력
친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
2
3
4
2
2
4
알고리즘 분류 : 해싱, 최소 스패닝 트리, 강한 연결 요소, Disjoint-set, 최대 독립 집합
*/
#include <bits/stdc++.h>
#define MAXI 200000 + 1
using namespace std;
int parent[MAXI];
int num[MAXI];
int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}
int merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return num[x];
	parent[y] = x;
	num[x] += num[y];
	num[y] = 1;
	return num[x];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int f, cnt = 0; cin >> f;
		for (int i = 0; i <= f * 2; i++) parent[i] = i, num[i] = 1;
		map<string, int> m;
		for (int i = 0; i < f; i++) {
			string input1, input2;
			int x, y;
			cin >> input1 >> input2;
			if (!m.count(input1)) m[input1] = cnt++;
			x = m[input1];
			if (!m.count(input2)) m[input2] = cnt++;
			y = m[input2];
			cout << merge(x, y) << "\n";
		}
	}
}