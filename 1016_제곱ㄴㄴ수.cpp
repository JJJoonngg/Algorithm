/*
문제
어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. 
min과 max가 주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

입력
첫째 줄에 min과 max가 주어진다. min은 1보다 크거나 같고, 1,000,000,000,000보다 작거나 같은 자연수이고, max는 min보다 크거나 같고, min+1,000,000보다 작거나 같은 자연수이다.
1 10
출력
첫째 줄에 [min,max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다.
7
**에라토스테네스의 체**
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