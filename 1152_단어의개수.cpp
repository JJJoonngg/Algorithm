/*
https://www.acmicpc.net/problem/1152
��
���� ��ҹ��ڿ� ���⸸���� �̷���� ���ڿ��� �־�����. �� ���ڿ����� �� ���� �ܾ ������? �̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, �� �ܾ ���� �� �����ϸ� ������ Ƚ����ŭ ��� ����� �Ѵ�.

�Է�
ù �ٿ� ���� ��ҹ��ڿ� ����� �̷���� ���ڿ��� �־�����. �� ���ڿ��� ���̴� 1,000,000�� ���� �ʴ´�. 
�ܾ�� ���� �� ���� ���еǸ�, ������ �����ؼ� ������ ���� ����. ���� ���ڿ��� �հ� �ڿ��� ������ ���� ���� �ִ�.
The Curious Case of Benjamin Button
 Mazatneunde Wae Teullyeoyo
Teullinika Teullyeotzi
���
ù° �ٿ� �ܾ��� ������ ����Ѵ�.
6
3
2
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXI 1000001
using namespace std;
char c[MAXI];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int res = 0;
	cin.getline(c, MAXI, '\n');
	char* token = strtok(c, " ");
	while (token != NULL) {
		res++;
		token = strtok(NULL, " ");
	}
	cout << res << "\n";
}