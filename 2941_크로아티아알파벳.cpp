/*
문제
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 다음과 같이 변경해서 입력했다.

예를 들어, ljes=njak은 크로아티아 알파벳 6개로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

입력
첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
문제 설명에 나와있는 크로아티아 알파벳만 주어진다.
ljes=njak
ddz=z=
nljj
c=c=

출력
입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
6
3
3
2
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	string input;
	string sample[] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	cin >> input;
	for (int i = 0; i < 8; i++) {
		int check = input.find(sample[i]);
		if (check >= 0) {
			input.erase(check, sample[i].length());
			input.insert(check, "!");
			i--;
		}
	}
	cout << input.length() << endl;
	return 0;
}