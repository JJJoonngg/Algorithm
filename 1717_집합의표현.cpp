/*
����
�ʱ⿡ {0}, {1}, {2}, ... {n} �� ���� n+1���� ������ �̷�� �ִ�. ���⿡ ������ �����, �� ���Ұ� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� ������ �����Ϸ��� �Ѵ�.

������ ǥ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n(1��n��1,000,000), m(1��m��100,000)�� �־�����. m�� �Է����� �־����� ������ �����̴�. 
���� m���� �ٿ��� ������ ������ �־�����. �������� 0 a b�� ���·� �Է��� �־�����. 
�̴� a�� ���ԵǾ� �ִ� ���հ�, b�� ���ԵǾ� �ִ� ������ ��ģ�ٴ� �ǹ��̴�. 
�� ���Ұ� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� ������ 1 a b�� ���·� �Է��� �־�����. 
�̴� a�� b�� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� �����̴�. a�� b�� n ������ �ڿ����Ǵ� 0�̸� ���� ���� �ִ�.
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
���
1�� �����ϴ� �Է¿� ���ؼ� �� �ٿ� �ϳ��� YES/NO�� ����� ����Ѵ�. (yes/no �� ����ص� �ȴ�)
NO
NO
YES
�˰��� �з� : Disjoint-set
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