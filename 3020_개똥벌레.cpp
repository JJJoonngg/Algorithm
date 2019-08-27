/*
문제
개똥벌레 한 마리가 장애물(석순과 종유석)로 가득찬 동굴에 들어갔다. 동굴의 길이는 N미터이고, 높이는 H미터이다. 
(N은 짝수) 첫 번째 장애물은 항상 석순이고, 그 다음에는 종유석과 석순이 번갈아가면서 등장한다.

동굴의 크기와 높이, 모든 장애물의 크기가 주어진다. 
이때, 개똥벌레가 파괴해야하는 장애물의 최솟값과 그러한 구간이 총 몇 개 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 H가 주어진다. N은 항상 짝수이다. (2 ≤ N ≤ 200,000, 2 ≤ H ≤ 500,000)
다음 N개 줄에는 장애물의 크기가 순서대로 주어진다. 장애물의 크기는 H보다 작은 양수이다.
14 5
1
3
4
2
2
4
3
4
3
3
3
2
3
3
출력
첫째 줄에 개똥벌레가 파괴해야 하는 장애물의 최솟값과 그러한 구간의 수를 공백으로 구분하여 출력한다.
7 2
알고리즘 분류: 정렬, 이분 탐색
*/
#include <bits/stdc++.h>
#define INF 1e9
#define MAXI 500000 + 1
using namespace std;
int bottom[MAXI], top[MAXI];
int n, h, res = INF, tmp, cnt = 1;
int inputBottom, inputTop, maxBottom = 0, maxTop = 0;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++) {
		cin >> inputBottom >> inputTop;
		bottom[inputBottom]++;
		top[inputTop]++;
		maxBottom = max(maxBottom, inputBottom);
		maxTop = max(maxTop, inputTop);
	}
	for (int i = maxBottom; i >= 1; i--) bottom[i] += bottom[i + 1];
	for (int i = maxTop; i >= 1; i--) top[i] += top[i + 1];
	
	for (int i = 1; i <= h; i++) {
		int tmp = bottom[i] + top[h - i + 1];
		if (res > tmp) cnt = 1, res = tmp;
		else if (res == tmp) cnt++;
	}
	cout << res << " " << cnt << "\n";
}