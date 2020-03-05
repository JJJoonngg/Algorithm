#include <bits/stdc++.h>
#define MAXI
using namespace std;
int a, b, idx = 0, cnt = 0;
string input;
map<string, int> m;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> input;
		if (m.size() != 0 && m.find(input) != m.end())cnt++;
		m.insert(make_pair(input, idx++));
	}
	for (int j = 0; j < b; j++) {
		cin >> input;
		if (m.size() != 0 && m.find(input) != m.end())cnt++;
		m.insert(make_pair(input, idx++));
	}
	cout << m.size() - cnt << "\n";
	return 0;
}