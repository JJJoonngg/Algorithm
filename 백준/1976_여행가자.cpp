/*
����
�����̴� ģ����� �Բ� ������ ������ �Ѵ�. �ѱ����� ���ð� N�� �ְ� ������ �� ���� ���̿� ���� ���� ����, ���� ���� �ִ�.
�������� ���� ������ �־����� ��, �� ���� ��ΰ� ������ ������ �˾ƺ���. ���� �߰��� �ٸ� ���ø� �����ؼ� ������ �� ���� �ִ�.
���� ��� ���ð� 5�� �ְ�, A-B, B-C, A-D, B-D, E-A�� ���� �ְ�, �������� ���� ��ȹ�� E C B C D ��� E-A-B-C-B-C-B-D��� �����θ� ���� ������ �޼��� �� �ִ�.

���õ��� ������ ���õ� ���� ���� ���ΰ� �־��� �ְ�, �������� ���� ��ȹ�� ���� ���õ��� ������� �־����� ��(�ߺ� ����) �������� ���θ� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ������ �� N�� �־�����. N�� 200�����̴�. ��° �ٿ� ���� ��ȹ�� ���� ���õ��� �� M�� �־�����.
M�� 1000�����̴�. ���� N * N ����� ���� ������ �� ���ð� ����Ǿ������� ���� ������ �־�����.
1�̸� ����� ���̰� 0�̸� ������ ���� ���� ���̴�. A�� B�� ����Ǿ����� B�� A�� ����Ǿ� �ִ�. ������ �ٿ��� ���� ��ȹ�� �־�����.
3
3
0 1 0
1 0 1
0 1 0
1 2 3
���
ù �ٿ� �����ϸ� YES �Ұ����ϸ� NO�� ����Ѵ�.
YES
*/
#include <bits/stdc++.h>
#define MAXI 200 + 1
using namespace std;
int n, m;
int arr[MAXI];
int res[1001];
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int input;  cin >> input;
			if (input) merge(i, j);
		}
	}
	bool flag = true;
	for (int i = 0; i < m; i++)	cin >> res[i];
	for (int i = 0; i < m - 1; i++) 
		if (find(res[i]) != find(res[i + 1])) {	
			flag = false; 
			break;
		}
	if (flag) cout << "YES\n";
	else cout << "NO\n";	
}