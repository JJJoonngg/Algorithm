/*
https://www.acmicpc.net/problem/10610
문제
어느날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에,
그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

입력
N을 입력받는다. N는 최대 10^5개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.
30
102
2931
출력
미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.
30
210
-1
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXI 100001
using namespace std;
char arr[MAXI] = { 0, };
long long sum = 0;
bool check = false;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> arr; int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		if (arr[i] == '0')	check = true;
		sum += arr[i];
	}
	if (!check) cout << "-1\n";
	else {
		sort(arr, arr + len);
		if (!(sum % 3)) {
			for (int i = len - 1; i >= 0; i--) 
				cout << arr[i];
			cout << "\n";
		}
		else cout << "-1\n";
	}
}