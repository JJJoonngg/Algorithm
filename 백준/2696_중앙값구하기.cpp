/*
https://www.acmicpc.net/problem/2696
����
� ������ �а�, Ȧ����° ���� ���� �� ����, ���ݱ��� �Է¹��� ���� �߾Ӱ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ������ 1,5,4,3,2 �̸�, Ȧ����° ���� 1��° ��, 3��° ��, 5��° ���̰�, 
1��° ���� �о��� �� �߾Ӱ��� 1, 3��° ���� �о��� ���� 4, 5��° ���� �о��� ���� 3�̴�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1<=T<=1,000)�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�� M(1<=M<=9999, M=Ȧ��)�� �־�����, 
�� ���� �ٺ��� �� ������ ���Ұ� ���ʴ�� �־�����. ���Ҵ� �� �ٿ� 10���� ���������ְ�, 32��Ʈ ��ȣ�ִ� �����̴�. (��κ��� ���� int)
3
9
1 2 3 4 5 6 7 8 9
9
9 8 7 6 5 4 3 2 1
23
23 41 13 22 -3 24 -31 -11 -8 -7
3 5 103 211 -311 -45 -67 -73 -81 -99
-33 24 56
���
�� �׽�Ʈ ���̽��� ���� ù° �ٿ� ����ϴ� �߾Ӱ��� ������ ����ϰ�, 
��° �ٿ��� Ȧ�� ��° ���� ���� �� ���� ���� �߾Ӱ��� ���ʴ�� �������� �����Ͽ� ����Ѵ�. 
�̶�, �� �ٿ� 10���� ����ؾ� �Ѵ�.
5
1 2 3 4 5
5
9 8 7 6 5
12
23 23 22 22 13 3 5 5 3 -3
-7 -3
*/
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n = 0;
		cin >> n;
		cout << (n + 1) / 2 << "\n";
		priority_queue <int, vector<int>, greater<int>> minHeap;
		priority_queue<int> maxHeap;
		for (int i = 1, idx = 0; i <= n; i++) {
			int tmp; cin >> tmp;
			if (minHeap.size() == maxHeap.size()) {
				if (minHeap.empty()) {
					maxHeap.push(tmp);
				}
				else {
					if (minHeap.top() <= tmp) {
						int a = minHeap.top();
						minHeap.pop();
						minHeap.push(tmp);
						tmp = a;
					}
					maxHeap.push(tmp);
				}
			}
			else {
				if (maxHeap.top() > tmp) {
					int a = maxHeap.top();
					maxHeap.pop();
					maxHeap.push(tmp);
					tmp = a;
				}
				minHeap.push(tmp);
			}
			if (minHeap.size() != maxHeap.size()) {
				cout << maxHeap.top() << " ";
				idx++;
				if (!(idx % 10)) {cout << "\n";	idx = 0;}
			}
		}
		cout << "\n";
	}
}