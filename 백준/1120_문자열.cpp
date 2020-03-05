/*
https://www.acmicpc.net/problem/1120
문제
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.
두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

1.A의 앞에 아무 알파벳이나 추가한다.
2.A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. A와 B의 길이는 최대 50이고, A의 길이는 B의 길이보다 작거나 같고, 알파벳 소문자로만 이루어져 있다.
adaabc aababbc

출력
A와 B의 길이가 같으면서, A와 B의 차이를 최소가 되도록 했을 때, 그 차이를 출력하시오.
2
알고리즘 분류 : 그리디 알고리즘, 브루트 포스, 문자열 처리, 시뮬레이션
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXI 51
using namespace std;
char arrA[MAXI], arrB[MAXI];
int res = 0;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> arrA >> arrB;
	int la = strlen(arrA), lb = strlen(arrB);
	if (la == lb) {
		for (int i = 0; i < la; i++)
			if (arrA[i] != arrB[i])
				res++;
	}
	else {
		res = la;
		for (int i = 0; i <= lb - la; i++) {
			int tmp = 0;
			for (int j = 0; j < la; j++)
				if (arrA[j] != arrB[i + j])
					tmp++;
			res = min(res, tmp);
		}
	}
	cout << res << "\n";
}