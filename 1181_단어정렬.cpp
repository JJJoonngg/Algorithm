/*
https://www.acmicpc.net/problem/1181
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
입력
첫째 줄에 단어의 개수 N이 주어진다. (1≤N≤20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> v;
bool compare(string s1,string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	else
		return s1.length() < s2.length();
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n - 1; i++) {
		if (v[i].length() == v[i + 1].length() && v[i] == v[i + 1]) continue;
		cout << v[i] << "\n";
	}
	cout << v[n - 1] << "\n";
}