/*
https://www.acmicpc.net/problem/11654
문제
알파벳 소문자, 대문자, 숫자 0-9중 하나가 주어졌을 때, 주어진 글자의 아스키 코드값을 출력하는 프로그램을 작성하시오.

입력
알파벳 소문자, 대문자, 숫자 0-9 중 하나가 첫째 줄에 주어진다.
A
C
0
9
a
z
출력
입력으로 주어진 글자의 아스키 코드 값을 출력한다.
65
67
48
57
97
122
*/
#include <iostream>
int main() {
	char input; scanf("%c", &input);
	printf("%d\n", input);
}