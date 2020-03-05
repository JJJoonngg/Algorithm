/*
https://www.acmicpc.net/problem/12738
제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)
6
10 20 10 30 20 50
출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
4
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (i == 0) v.push_back(tmp);
		if (v.back() < tmp)
			v.push_back(tmp);
		else {
			auto it = lower_bound(v.begin(), v.end(), tmp);
			*it = tmp;
		}
	}
	cout << v.size() << "\n";
}