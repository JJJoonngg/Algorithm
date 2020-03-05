/*
입력
입력의 첫째 줄에 A,B,C가 공백으로 구분되어 주어진다. (1≤A,B≤108) (1≤C≤10100)
1 1 1
3 5 5
출력
A에 B를 C번 XOR한 결과를 출력한다.
0 6
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b; string c;
	cin >> a >> b >> c;
	if (c[c.length() - 1] & 1) cout << (a ^ b) << "\n";
	else cout << a << "\n";
}