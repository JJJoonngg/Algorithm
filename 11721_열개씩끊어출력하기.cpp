/*
https://www.acmicpc.net/problem/11721
����
���ĺ� �ҹ��ڿ� �빮�ڷθ� �̷���� ���̰� N�� �ܾ �־�����.

�� �ٿ� 10���ھ� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ �־�����. �ܾ�� ���ĺ� �ҹ��ڿ� �빮�ڷθ� �̷���� ������, ���̴� 100�� ���� �ʴ´�. 
���̰� 0�� �ܾ�� �־����� �ʴ´�.
BaekjoonOnlineJudge
OneTwoThreeFourFiveSixSevenEightNineTen
���
�Է����� �־��� �ܾ �� ���� ��� �� �ٿ� �ϳ��� ����Ѵ�. �ܾ��� ���̰� 10�� ����� �ƴ� ��쿡�� ������ �ٿ��� 10�� �̸��� ���ڸ� ����� ���� �ִ�.
BaekjoonOn
lineJudge

OneTwoThre
eFourFiveS
ixSevenEig
htNineTen
*/
#include <iostream>
using namespace std;
int main() {
	char input[101];
	scanf("%s", input);
	int i = 0;
	while (true) {
		printf("%c", input[i++]);
		if (!(i % 10)) printf("\n");
		if (input[i] == '\0' ) break;
	}
	printf("\n");
}