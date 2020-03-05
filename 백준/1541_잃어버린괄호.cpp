/*
https://www.acmicpc.net/problem/1541
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.
55-50+40
출력
첫째 줄에 정답을 출력한다.
-35
*/
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char c[51];  cin >> c;
	int sum = 0, a = 0, flag = 0;
	for (int i = 0; i < strlen(c); i++) {
		if ('0' <= c[i] && c[i] <= '9') {
			a *= 10; a += c[i] - '0';
		}
		else {
			if (!flag) sum += a;
			else sum -= a;
			if (c[i] == '-' && !flag) flag = 1;
			a = 0;
		}
	}
	if (!flag) sum += a;
	else sum -= a;
	cout << sum<< "\n";
}