/*
문제
IQ Test의 문제 중에는 공통된 패턴을 찾는 문제가 있다. 숫자의 수열이 주어졌을 때, 다음 수를 찾는 문제이다.
예를 들어, 1, 2, 3, 4, 5가 주어졌다. 다음 숫자는 무엇인가? 당연히 답은 6이다. 
약간 더 어려운 문제를 보면, 3, 6, 12, 24, 48이 주어졌을 때, 다음 숫자는 무엇인가? 역시 답은 96이다.
이제 제일 어려운 문제를 보자.
1, 4, 13, 40이 주어졌을 때, 다음 숫자는 무엇일까? 답은 121이다. 그 이유는 항상 다음 수는 앞 수*3+1이기 때문이다.
은진이는 위의 3문제를 모두 풀지 못했으므로, 자동으로 풀어주는 프로그램을 작성하기로 했다. 
항상 모든 답은 구하는 규칙은 앞 수*a + b이다. 그리고, a와 b는 정수이다.
수 N개가 주어졌을 때, 규칙에 맞는 다음 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 N개의 수가 주어진다. 이 수는 모두 절댓값이 100보다 작거나 같은 정수이다.
4
1 4 13 40

출력
다음 숫자를 출력한다. 만약 다음 숫자가 여러 개일 경우에는 A를 출력하고, 다음 숫자를 구할 수 없는 경우에는 B를 출력한다.
121
*/
#include <iostream>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	int N;
	cin >> N;
	int* number = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	if (N == 1) {
		cout << "A" << endl;
	}
	else if (N == 2) {
		if (number[0] == number[1]) {
			cout << number[0] << endl;
		}
		else {
			cout << "A" << endl;
		}
	}
	else if(N >= 3){
		int check = 1;
		int first = number[0];
		int second = number[1];
		int third = number[2];
		
		if (second == first) {
			a = 0;
			b = second;
		}
		else {
			a = (third - second) / (second - first);
			b = second - (first * a);
		}

		for(int i=0;i<N-1;i++){
			
			int checkValue = number[i] * a + b;
			int checkNextValue = number[i + 1];

			if (!(checkValue == checkNextValue)) {
				check = 0;
			}
		}
	
		if (check == 1) {
			int nextValue = number[N - 1] * a + b;
			cout << nextValue << endl;
		}
		if (check == 0) {
			cout << "B" << endl;
		}
		
	}

	delete[] number;
	return 0;
}