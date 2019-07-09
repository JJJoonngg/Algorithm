/*
https://www.acmicpc.net/problem/9251
����
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.

���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.
ACAYKP
CAPCAK
���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.
4
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 1002
using namespace std;
char s1[MAX], s2[MAX];
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
}