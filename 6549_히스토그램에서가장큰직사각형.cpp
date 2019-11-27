/*
https://www.acmicpc.net/problem/6549
����
������׷����� ���� ���̰� ū ���簢���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �׽�Ʈ ���̽� ���� ���� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���簢���� �� n�� ���� ó������ �־�����. (1 �� n �� 100,000) �� ���� n���� ���� h1, ..., hn (0 �� hi �� 1,000,000,000)�� �־�����. �� ���ڵ��� ������׷��� �ִ� ���簢���� �����̸�, ���ʺ��� �����ʱ��� ������� �־�����.
��� ���簢���� �ʺ�� 1�̰�, �Է��� ������ �ٿ��� 0�� �ϳ� �־�����.
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
���
�� �׽�Ʈ ���̽��� ���ؼ�, ������׷����� ���� ���̰� ū ���簢���� ���̸� ����Ѵ�.
8
4000

�˰��� �з� : ���׸�Ʈ Ʈ��, ����, ��������
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