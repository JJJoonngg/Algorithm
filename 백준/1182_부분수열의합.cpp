/*
https://www.acmicpc.net/problem/1182
����
N���� ������ �̷���� ������ ���� ��, ���̰� ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 20, |S| �� 1,000,000)
��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.
5 0
-7 -3 -2 5 8
���
ù° �ٿ� ���� S�� �Ǵ� �κм����� ������ ����Ѵ�.
1
*/
#include <iostream>
int  arr[21], n, s, ans = 0;
void dfs(int index, int sum) {
	if (index >= n) return;

	if (sum + arr[index] == s) ans++;

	dfs(index+1, sum + arr[index]);
	dfs(index + 1, sum);
}
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	dfs(0, 0);
	printf("%d\n", ans);
}