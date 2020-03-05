/*
https://www.acmicpc.net/problem/2966
����
�����, â����, �����̴� ����� ������ �ڶ��ϴ� Sogang ACM-ICPC Team�� �����Ϸ��� �Ѵ�. 
������, �����Ϸ��� �ϴ� ��� �����ڴ� C��� �ʱ������ ����ؾ� �Ѵ�. �̵��� C�� �� �� �𸥴�. ����, �ʱ������ ��� �������� �Ѵ�.

����̴� A, B, C, A, B, C, A, B, C, A, B, C, ...�� ���� ���� ����� �� �ִٰ� �����Ѵ�.
������, â���̴� B, A, B, C, B, A, B, C, B, A, B, C, ...�� ���� ��� ����� ������ �������̶�� �����Ѵ�.
����������, �����̴� ����̿� â���̸� ������鼭 C, C, A, A, B, B, C, C, A, A, B, B, ...�� ���� ���� ����Ѵٰ� ���ߴ�.

�ʱ������ ������ �־����� ��, �����, â����, ������ �߿��� ���� ���� ������ ���� ����� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ʱ������ ������ �� N�� �־�����. (1 �� N �� 100)
��° �ٿ��� ������ ������ �־�����.
5
BAACC
���
ù° �ٿ� ���� ���� ������ ���� ����� �� ������ �������� ����Ѵ�.
���� �ٿ��� ���� ���� ������ ���� ����� ���̵� �� �ٿ� �ϳ��� ����Ѵ�. 
������� ���̵�� Adrian, 
â������ ���̵�� Bruno, 
�������� ���̵�� Goran�̴�. 
���̵� ���� ���� ����ϴ� ��쿡�� �����, â����, ������ ������ ����Ѵ�.
3
Bruno
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n;
char input[101];
char sang[] = { 'A','B','C' };
char chang[] = { 'B','A','B','C' };
char hyun[] = { 'C','C','A','A','B','B' };
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; for (int i = 0; i < n; i++)cin >> input[i];
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] == sang[i % 3]) a++;
		if (input[i] == chang[i % 4]) b++;
		if (input[i] == hyun[i % 6]) c++;
	}
	int res = max(max(a, b), c);
	cout << res << "\n";
	if (res == a) cout << "Adrian\n";
	if (res == b) cout << "Bruno\n";
	if (res == c) cout << "Goran\n";
}