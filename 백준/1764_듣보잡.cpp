/*
문제
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다.
이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다.
이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.
3 4
ohhenrie
charlie
baesangwook
abc
obama
baesangwook
ohhenrie
clinton
abc
출력
듣보잡의 수와 그 명단을 사전순으로 출력한다.
2
baesangwook
ohhenrie
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<string> v, list;
	int n, m;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		string tmp; cin >> tmp;
		if (binary_search(v.begin(), v.end(), tmp)) {
			list.push_back(tmp);
		}
	}
	sort(list.begin(), list.end());
	cout << list.size() << "\n";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << "\n";
	}
}