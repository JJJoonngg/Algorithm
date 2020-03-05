/*
https://www.acmicpc.net/problem/10775
문제
오늘은 신승원의 생일이다.
박승원은 생일을 맞아 신승원에게 인천국제공항을 선물로 줬다.
공항에는 G개의 게이트가 있으며 각각은 1에서 G까지의 번호를 가지고 있다.
공항에는 P개의 비행기가 순서대로 도착할 예정이며, 당신은 i번째 비행기를 1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 하나에 영구적으로 도킹하려 한다. 
비행기가 도킹된 게이트에는 다른 비행기가 도착할 수 없다.

이렇게 공항을 운영할 경우 간혹 비행기가 어떤 곳에도 도킹하지 못하는 사고가 발생한다. 
이러한 사고가 일어나면 공항의 평판이 급속히 나빠져, 이후 어떤 비행기도 도착하지 않으려 할 것이다.

신승원은 가장 많은 비행기를 공항에 도킹시켜서 박승원을 행복하게 하고 싶어한다. 승원이는 비행기를 최대 몇 대 도킹시킬 수 있는가?

입력
첫 번째 줄에는 게이트의 수 G (1 ≤ G ≤ 10^5)가 주어진다.
두 번째 줄에는 비행기의 수 P (1 ≤ P ≤ 10^5)가 주어진다.
이후 P개의 줄에 gi (1 ≤ gi ≤ G) 가 주어진다.
4
3
4
1
1

4
6
2
2
3
3
4
4
출력
승원이가 도킹시킬 수 있는 최대의 비행기 수를 출력한다.
2
3
힌트
예제 1 : [2][?][?][1] 형태로 도킹시킬 수 있다. 3번째 비행기는 도킹시킬 수 없다.
예제 2 : [1][2][3][?] 형태로 도킹 시킬 수 있고, 4번째 비행기는 절대 도킹 시킬 수 없어서 이후 추가적인 도킹은 불가능하다.
알고리즘 분류 : Disjoint-set
*/
#include <bits/stdc++.h>
#define MAXI 100000 + 1
using namespace std;
int p, g, cnt = 0;
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
	cin >> g >> p;
	for (int i = 0; i <= g; i++) arr[i] = i;
	while (p--) {
		int input; cin >> input;
		int tmp = find(input);
		if (!tmp) break;
		cnt++; merge(tmp, tmp - 1);
	}
	cout << cnt << "\n";
}