/*
문제
세준이는 N개의 빨대를 가지고 있다. N개의 빨대 중에 3개의 빨대를 선택했을 때, 
이 빨대로 삼각형을 만들 수 있다면, 세 변의 길이의 합의 최대값을 구하고 싶다.

입력
첫째 줄에 빨대의 개수 N이 주어진다. N은 3보다 크거나 같고, 1,000,000보다 작거나 같은 자연수이다. 
둘째 줄에 빨대의 길이가 공백을 사이에 두고 주어진다. 빨대의 길이는 1,000,000보다 작거나 같다.
3
1
2
3

출력
첫째 줄에 삼각형 세 변의 길이의 합의 최대값을 출력한다. 
만약 삼각형을 만들 수 없으면 -1을 출력한다.
-1
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int max = -1;
	cin >> N;

	int* straw = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> straw[i];
	}
	
	sort(straw, straw + N);
	
	for (int i = 0; i <N-2; i++) {
		if (straw[i + 2] < straw[i] + straw[i + 1]) {
			max = straw[i + 2] + straw[i] + straw[i + 1];
		}
	}
	cout << max << endl;


	delete[] straw;
	return 0;
}