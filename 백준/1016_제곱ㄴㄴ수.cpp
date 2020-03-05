/*
����
� �� X�� 1���� ū �������� ������ �������� ���� ��, ������������� �Ѵ�. �������� ������ �����̴�. 
min�� max�� �־�����, min�� max�� ������ ���̿� ������������ �� �� �ִ��� ����Ѵ�.

�Է�
ù° �ٿ� min�� max�� �־�����. min�� 1���� ũ�ų� ����, 1,000,000,000,000���� �۰ų� ���� �ڿ����̰�, max�� min���� ũ�ų� ����, min+1,000,000���� �۰ų� ���� �ڿ����̴�.
1 10
���
ù° �ٿ� [min,max]������ ������������ �� ������ ����Ѵ�.
7
**�����佺�׳׽��� ü**
*/
#include <iostream>
#define MAX 1000001
using namespace std;
bool check[MAX];
long long minN, maxN, num, i, j;
int cnt = 0;
int main() {	
	scanf("%lld %lld", &minN, &maxN);
	for (i = 2; i*i <= maxN; i++) {
		long long start = minN / (i*i);
		if (start * (i*i) != minN) start++;
		for (j = start; i*i*j <= maxN; j++) {
			check[i*i*j - minN]++;
		}
	}
	for (int k = 0; k <= maxN - minN; k++)
		if (!check[k]) cnt++;
	printf("%d\n", cnt);
	return 0;
}