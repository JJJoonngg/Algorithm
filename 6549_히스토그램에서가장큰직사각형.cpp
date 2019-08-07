/*
https://www.acmicpc.net/problem/6549
문제
히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다.
모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다.
8
4000

알고리즘 분류 : 세그먼트 트리, 스택, 분할정복
*/
#include <bits/stdc++.h>
#define MAXI 100000 + 1
using namespace std;
typedef long long LL;
int n;
int arr[MAXI];
int tree[MAXI << 2];
void init(int start, int end, int node) {
	if (start == end) tree[node] = start;
	else {
		int mid = (start + end) / 2;
		init(start, mid, node * 2);
		init(mid + 1, end, node * 2 + 1);
		tree[node] = arr[tree[node * 2]] <= arr[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1];
	}
}
int query(int start, int end, int node, int nodeleft, int noderight) {
	if (nodeleft > end || noderight < start) return -1;
	if (nodeleft <= start && end <= noderight) return tree[node];

	int mid = (start + end) / 2;
	int tmpleft = query(start, mid, node * 2, nodeleft, noderight);
	int tmpright = query(mid + 1, end, node * 2 + 1, nodeleft, noderight);

	if (tmpleft == -1) return tmpright;
	else if (tmpright == -1) return tmpleft;
	else return arr[tmpleft] <= arr[tmpright] ? tmpleft : tmpright;
}
LL getMax(int start, int end) {
	LL area, tmp;
	int minIndex = query(0, n - 1, 1, start, end);
	area = (LL)(end - start + 1)*(LL)(arr[minIndex]);
	if (start <= minIndex - 1) {
		tmp = getMax(start, minIndex - 1);
		area = max(area, tmp);
	}
	if (end >= minIndex + 1) {
		tmp = getMax(minIndex + 1, end);
		area = max(area, tmp);
	}
	return area;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> arr[i];
		init(0, n - 1, 1);
		cout << getMax(0, n - 1) << "\n";
	}
}