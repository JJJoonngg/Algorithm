/*
https://www.acmicpc.net/problem/1722
문제
1부터 N까지의 수를 임의로 배열한 순열은 총 N! = N×(N-1)×…×2×1 가지가 있다.
임의의 순열은 정렬을 할 수 있다. 예를 들어  N=3인 경우 {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}의 순서로 생각할 수 있다. 
첫 번째 수가 작은 것이 순서상에서 앞서며, 첫 번째 수가 같으면 두 번째 수가 작은 것이, 두 번째 수도 같으면 세 번째 수가 작은 것이….
N이 주어지면, 아래의 두 소문제 중에 하나를 풀어야 한다. k가 주어지면 k번째 순열을 구하고, 
임의의 순열이 주어지면 이 순열이 몇 번째 순열인지를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤20)이 주어진다. 둘째 줄의 첫 번째 수는 소문제 번호이다. 1인 경우 k(1≤k≤N!)를 입력받고, 
2인 경우 임의의 순열을 나타내는 N개의 수를 입력받는다. N개의 수에는 1부터 N까지의 정수가 한 번씩만 나타난다.
4
1 3
4
2 1 3 2 4
출력
k번째 수열을 나타내는 N개의 수를 출력하거나, 몇 번째 수열인지를 출력하면 된다
1 3 2 4
3

알고리즘 분류 :수학, 구현, 순열
*/
#include <bits/stdc++.h>
using namespace std;
int n, k;
bool check[21];
long long factorial[21], res = 0;
vector<int> v;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	v.resize(n);
	factorial[0] = 1;
	for (int i = 1; i < 21; i++) factorial[i] = factorial[i - 1] * i;
	if (k == 1) {
		long long input;
		cin >> input;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[j]) continue;
				if (factorial[n - 1 - i] < input)
					input -= factorial[n - 1 - i];
				else {
					v[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) cout << v[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) cin >> v[i];
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) 
				if (!check[j]) res += factorial[n - 1 - i];
			check[v[i]] = true;
		}
		cout << res + 1 << "\n";
	}
}