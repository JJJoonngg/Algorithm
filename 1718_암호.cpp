#include <bits/stdc++.h>
constexpr auto MAXI = 30001;
using namespace std;
char s[MAXI];
string res = "";
string pwd;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin.getline(s, MAXI, '\n');
	cin >> pwd;
	int siz = pwd.length();
	int a = (int)'a';
	int z = (int)'z';
	int space = (int)' ';
	for (int i = 0, idx = 0; i < MAXI; i++, idx++) {
		if (siz == idx) idx = 0;
		if (s[i] == NULL) break;
		if (int(s[i]) == space) continue;
		s[i] -= pwd[idx] + 1;
		if (s[i] < 0) s[i] += 'z' + 1;
		if (s[i] > 'z') s[i] -= 'a';
		if (s[i] < 'a') s[i] += 'a';
	}
	cout << s << "\n";
	return 0;
}