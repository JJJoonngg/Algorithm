/*
����
�����̴� �Ҽ� ��Ʈ��ũ ����Ʈ���� ģ���� ����� ���� �����ϴ� ģ���̴�. 
��ǥ�� ������ ��̰� �ֵ���, �����̴� �Ҽ� ��Ʈ��ũ ����Ʈ���� ģ���� ������ ���� ����̴�.
� ����Ʈ�� ģ�� ���谡 ���� ������� �־����� ��, �� ����� ģ�� ��Ʈ��ũ�� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ģ�� ��Ʈ��ũ�� ģ�� ���踸���� �̵��� �� �ִ� ���̸� ���Ѵ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� ģ�� ������ �� F�� �־�����, 
�� ���� 100,000�� ���� �ʴ´�. ���� F���� �ٿ��� ģ�� ���谡 ���� ������� �־�����.
ģ�� ����� �� ������� ���̵�� �̷���� ������, ���ĺ� �빮�� �Ǵ� �ҹ��ڷθ� �̷���� ���� 20 ������ ���ڿ��̴�.
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty
���
ģ�� ���谡 ���� ������, �� ����� ģ�� ��Ʈ��ũ�� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
2
3
4
2
2
4
�˰��� �з� : �ؽ�, �ּ� ���д� Ʈ��, ���� ���� ���, Disjoint-set, �ִ� ���� ����
*/
#include <bits/stdc++.h>
#define MAXI 200000 + 1
using namespace std;
int parent[MAXI];
int num[MAXI];
int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}
int merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return num[x];
	parent[y] = x;
	num[x] += num[y];
	num[y] = 1;
	return num[x];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int f, cnt = 0; cin >> f;
		for (int i = 0; i <= f * 2; i++) parent[i] = i, num[i] = 1;
		map<string, int> m;
		for (int i = 0; i < f; i++) {
			string input1, input2;
			int x, y;
			cin >> input1 >> input2;
			if (!m.count(input1)) m[input1] = cnt++;
			x = m[input1];
			if (!m.count(input2)) m[input2] = cnt++;
			y = m[input2];
			cout << merge(x, y) << "\n";
		}
	}
}