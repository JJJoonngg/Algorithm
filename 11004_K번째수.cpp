/*
����
�� N�� A1, A2, ..., AN�� �־�����.
A�� �������� �������� ��, �տ������� K��° �ִ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 5,000,000)�� K (1 �� K �� N)�� �־�����.
��°���� A1, A2, ..., AN�� �־�����. (-109 �� Ai �� 109)
5 2
4 1 2 3 5

���
A�� �������� ��, �տ������� K��° �ִ� ���� ����Ѵ�.
2
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int* arr = new int[n + 1];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[k - 1] << endl;
	delete[] arr;
	return 0;
}