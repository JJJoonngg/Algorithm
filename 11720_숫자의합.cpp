/*
https://www.acmicpc.net/problem/11720
����
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.
1
1

5
54321

25
7000000000000000000000000

11
10987654321
���
�Է����� �־��� ���� N���� ���� ����Ѵ�.
1
15
7
46

�˰��� �з� : ���
*/
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, sum =0; cin >> n;
	char arr[101] = { 0, };
	cin >> arr;

	for (int i = 0; i < n; i++) sum += arr[i] - '0';
	
	cout << sum << "\n";
}