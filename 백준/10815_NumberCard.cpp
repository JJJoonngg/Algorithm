/*
문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 
숫자 M개가 주어졌을 때, 이 숫자가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N (1 ≤ N ≤ 500,000)이가 주어진다. 
둘째 줄에는 숫자 카드에 적혀있는 숫자가 주어진다. 숫자 카드에 적혀있는 숫자는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
두 숫자 카드에 같은 숫자가 적혀있는 경우는 없다.

셋째 줄에는 M (1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 숫자가 주어지며, 
이 숫자는 공백으로 구분되어져 있다. 이숫자도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
출력
첫째 줄에 입력으로 주어진 M개의 숫자에 대해서, 각 숫자가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.
1 0 0 1 1 0 0 1
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N, M;
void bfs(int start, int end, int data) {
	int mid = (start + end) / 2;
	if (start > end) {
		printf("0 ");
	}
	else {
		if (v[mid] == data) {
			printf("1 ");
			return;
		}
		else if (data > v[mid]) {
			start = mid + 1;
			bfs(start, end, data);
		}
		else if (data < v[mid]) {
			end = mid - 1;
			bfs(start, end, data);
		}
	}
}
int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int data;
		scanf("%d", &data);
		bfs(0, N - 1, data);
	}
	printf("\n");
	return 0;
}
