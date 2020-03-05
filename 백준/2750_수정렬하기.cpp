/*
https://www.acmicpc.net/problem/2750
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. 
��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. 
�� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.
5
5
2
3
4
1
���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
1
2
3
4
5
*/
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main() {
	cout.tie(NULL); cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int input; cin >> input;
		pq.push(input);
	}
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}