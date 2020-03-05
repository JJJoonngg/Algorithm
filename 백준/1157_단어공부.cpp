/*
https://www.acmicpc.net/problem/1157
����
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

�Է�
ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.
Mississipi
zZa
z
baaa
���
ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.
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