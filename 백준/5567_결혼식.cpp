/*
https://www.acmicpc.net/problem/5567
����
����̴� �ڽ��� ��ȥ�Ŀ� �б� ���� �� �ڽ��� ģ���� ģ���� ģ���� �ʴ��ϱ�� �ߴ�. 
������� ����� ��� N���̰�, �� �л����� �й��� ��� 1���� N�����̴�. ������� �й��� 1�̴�.

����̴� ������� ģ�� ���踦 ��� ������ ����Ʈ�� ������ �ִ�. �� ����Ʈ�� �������� ��ȥ�Ŀ� �ʴ��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������� ������ �� n (2 �� n �� 500)�� �־�����. ��° �ٿ��� ����Ʈ�� ���� m (1 �� m �� 10000)�� �־�����. 
���� �ٺ��� m�� �ٿ��� ģ�� ���� ai bi�� �־�����. (1 �� ai < bi �� n) ai�� bi�� ģ����� ���̸�, bi�� ai�� ģ�������̴�.
6
5
1 2
1 3
3 4
2 3
4 5
���
ù° �ٿ� ������� ��ȥ�Ŀ� �ʴ��ϴ� ������ ���� ����Ѵ�.
3
��Ʈ
2�� 3�� ������� ģ���̴�. ��, 3�� 4�� ģ���̱� ������, 4�� ������� ģ���� ģ���̴�. 5�� 6�� ģ���� �ƴϰ�, ģ���� ģ���� �ƴϴ�.
���� 2,3,4 3���� ģ���� ��ȥ�Ŀ� �ʴ��Ѵ�.
*/
#include <iostream>
#include <vector>
#define MAXI 500 + 1
using namespace std;
int n, m;
int visit[MAXI] = { 0, }, res[MAXI] = { 0, };
vector<int> v[MAXI];
void dfs(int from) {
	for (auto next : v[from]) 
		res[next] = true;
	
	if (from == 1) 
		for (auto next : v[from]) 
			dfs(next);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	int ans = 0;
	for (int i = 2; i <= n; i++) if (res[i]) ans++;
	cout << ans << "\n";
}