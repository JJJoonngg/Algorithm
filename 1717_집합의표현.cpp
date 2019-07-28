/*
문제
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다. m은 입력으로 주어지는 연산의 개수이다. 
다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다. 
이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 
두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 
이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. a와 b는 n 이하의 자연수또는 0이며 같을 수도 있다.
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
출력
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)
NO
NO
YES
알고리즘 분류 : Disjoint-set
*/
#include <bits/stdc++.h>
#define MAXI 1000000 + 1
using namespace std;
int n, m;
int arr[MAXI];
int find(int x) {
	if (x == arr[x]) return x;
	return arr[x] = find(arr[x]);
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	arr[x] = y;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) arr[i] = i;
	while (m--) {
		int type, A, B; cin >> type >> A >> B;
		if (!type) merge(A, B);
		else {
			if (find(A) == find(B)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}