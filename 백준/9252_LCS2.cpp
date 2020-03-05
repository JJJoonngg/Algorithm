/*
https://www.acmicpc.net/problem/9252
https://hsp1116.tistory.com/37
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
ACAYKP
CAPCAK
출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.
LCS가 여러 가지인 경우에는 아무거나 출력한다.
4
ACAK
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX 1002
using namespace std;
char s1[MAX], s2[MAX];
vector<char> output;
int dp[MAX][MAX] = { 0, };
int main() {
	scanf("%s %s", s1, s2);
	int a = strlen(s1);
	int b = strlen(s2);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (s1[i - 1] == s2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	printf("%d\n", dp[a][b]);
	while (dp[a][b] != 0) {
		if (dp[a][b] == dp[a - 1][b]) a--;
		else if (dp[a][b] == dp[a][b - 1]) b--;
		else {
			output.push_back(s1[a - 1]);
			a--; b--;
		}
	}
	for (int i = output.size()-1; i >= 0; i--) { printf("%c", output[i]); }
	printf("\n");
}