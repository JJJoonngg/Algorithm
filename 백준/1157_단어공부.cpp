/*
https://www.acmicpc.net/problem/1157
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.
Mississipi
zZa
z
baaa
출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
?
Z
Z
A
*/
#include <iostream>
#define MAXI 1000000 + 1
int main() {
	char input[MAXI]; scanf("%s", input);
	int arr[27] = { 0, }, res = -1, ans;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] - 'a' >= 0) arr[input[i] - 'a']++;
		else arr[input[i] - 'A']++;
	}
	for (int i = 0; i < 27; i++)
		if (arr[i] > res) 	res = arr[i], ans = i;
	for (int i = 0; i < 27; i++) {
		if (i == ans) continue;
		if (res == arr[i]) { printf("?\n"); return 0; }
	}
	printf("%c\n", ans + 'A');
}