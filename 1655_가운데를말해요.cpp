/*
https://www.acmicpc.net/problem/1655
����
�����̴� �������� "����� ���ؿ�" ������ �������ְ� �ִ�. �����̰� ������ �ϳ��� ��ĥ������ 
������ ���ݱ��� �����̰� ���� �� �߿��� �߰����� ���ؾ� �Ѵ�.
����, �׵��� �����̰� ��ģ ���� ������ ¦������� �߰��� �ִ� �� �� �߿��� ���� ���� ���ؾ� �Ѵ�.

���� ��� �����̰� �������� 1, 5, 2, 10, -99, 7, 5�� ������� ���ƴٰ� �ϸ�, 
������ 1, 1, 2, 2, 2, 2, 5�� ���ʴ�� ���ؾ� �Ѵ�. �����̰� ��ġ�� ���� �־����� ��, ������ ���ؾ� �ϴ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �����̰� ��ġ�� ������ ���� N�� �־�����. N�� 1���� ũ�ų� ����, 100,000���� �۰ų� ���� �ڿ����̴�. 
�� ���� N�ٿ� ���ļ� �����̰� ��ġ�� ������ ���ʴ�� �־�����. ������ -10,000���� ũ�ų� ����, 10,000���� �۰ų� ����.
7
1
5
2
10
-99
7
5
���
�� �ٿ� �ϳ��� N�ٿ� ���� �������� ������ ���ؾ��ϴ� ���� ������� ����Ѵ�.
1
1
2
2
2
2
5
*/
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> MinHeap;
	priority_queue<int> MaxHeap;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (MaxHeap.empty()) MaxHeap.push(tmp);
		else if (MinHeap.size() == MaxHeap.size()) MaxHeap.push(tmp);
		else MinHeap.push(tmp);
		if (!MaxHeap.empty() && !MinHeap.empty() && MinHeap.top() < MaxHeap.top()) {
			int a = MinHeap.top(), b = MaxHeap.top();
			MinHeap.pop(); MaxHeap.pop();
			MinHeap.push(b); MaxHeap.push(a);
		}
		cout << MaxHeap.top() << "\n";
	}
}