/*
https://www.acmicpc.net/problem/15786
석규는 해외로 저렴하고 간편하게 송금할 수 있는 센트비 서비스를 이용하여 CTP 왕국에 놀러간 형동이에게 돈을 보내주려고 한다.
하지만 안타깝게도 석규는 센트비 비밀번호를 까먹어버렸고 돈을 보내주지 못한다.
다행히도 석규는 평소에 포스트잇에 비밀번호를 적어놓는다. 비밀번호는 알파벳 대문자로만 구성이 되어있으며 석규는 이 중 일부를 정확히 기억하고 있다.
석규는 포스트잇을 확인하여 비밀번호를 입력하려고 했지만, 포스트잇은 여러 장 존재했고 이 중 어떤 포스트잇이 센트비 비밀번호가 적힌 포스트잇인지 모른다.
석규는 센트비 비밀번호의 알파벳 중 등장하는 순서대로 N글자만 정확히 기억하고 있으며 포스트잇 중에 이 순서를 갖는 포스트잇이 센트비 비밀번호일 가능성이 있는 포스트잇이다.
예를 들어, 석규가 ABB를 기억한다면 BBAB이 적힌 포스트잇은 비밀번호일 가능성이 없고, HAEBBC가 적힌 포스트잇은 비밀번호일 가능성이 있다.

석규는 형동이에게 송금해주기 위해 포스트잇들 중 비밀번호가 적힌 포스트잇일 가능성이 있는 포스트잇들을 따로 분류하려고 한다.
석규가 기억하는 알파벳 N글자와 포스트잇 M개가 주어질 때, 해당 포스트잇에 적힌 알파벳이 비밀번호일 가능성이 있는지 여부를 판단하여 보자.

입력
입력의 첫째 줄에 석규가 기억하는 원본 알파벳의 수 N(1 ≤ N ≤ 100)과 포스트잇의 개수 M(1 ≤ M ≤ 1000)이 주어진다.
다음 줄에 길이가 N인 알파벳 대문자로 이루어진 문자열 S가 주어진다.
이 후 M개의 줄에 알파벳 대문자로 이루어진 판별해야 할 포스트잇들이 주어진다. 모든 포스트잇에 적힌 문자열은 1000자 이하이다.
4 5
PPAP
PPAPP
PPPPA
APPPP
PPPAP
PAPAP

3 2
CTP
P
CHALLENGETHEPROGRAMING
출력
M개의 줄에 가능성 여부를 “true” , “false”로 답하여라.
true
false
false
true
true

false
true
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string input;
	int n, m;
	cin >> n >> m; cin >> input;
	while (m--) {
		bool flag = false;
		string tmp; cin >> tmp;
		for (int i = 0, idx = 0; tmp[i] !='\0';i++) {
			if (tmp[i] == input[idx]) idx++;
			if (idx == n) {	flag = true; break;	}
		}
		if (flag) cout << "true\n";
		else cout << "false\n";
	}
}