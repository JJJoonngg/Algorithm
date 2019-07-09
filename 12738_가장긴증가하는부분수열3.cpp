/*
https://www.acmicpc.net/problem/12738
��
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (-1,000,000,000 �� Ai �� 1,000,000,000)
6
10 20 10 30 20 50
���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
4
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (i == 0) v.push_back(tmp);
		if (v.back() < tmp)
			v.push_back(tmp);
		else {
			auto it = lower_bound(v.begin(), v.end(), tmp);
			*it = tmp;
		}
	}
	cout << v.size() << "\n";
}