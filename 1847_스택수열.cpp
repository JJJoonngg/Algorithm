/*
https://www.acmicpc.net/problem/1874
����
���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�.
������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ���� ���� ���߿� �� �ڷᰡ ���� ���� ������ (LIFO, Last in First out) Ư���� ������ �ִ�.

1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�. 
�̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. ������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������,
�ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. �̸� ����ϴ� ���α׷��� �ۼ��϶�.

�Է�
ù �ٿ� n (1 �� n �� 100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����. ���� ���� ������ �� �� ������ ���� ����.
8
4
3
6
8
7
5
2
1

5
1
2
5
3
4
���
�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�. push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.
+
+
+
+
-
-
+
+
-
+
+
-
-
-
-
-

NO

��Ʈ
1���� n������ ���� ���� ���ʷ� [push, push, push, push, pop, pop, push, push, pop, push, push, pop, pop, pop, pop, pop]
������ �����ϸ� ���� [4, 3, 6, 8, 7, 5, 2, 1]�� ���� �� �ִ�.
*/
#include <iostream>
#include <stack>
#include <vector>
#define MAXI 100000 + 1
using namespace std;
int arr[MAXI] = { 0, };
stack<int> s;
vector<char> res;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	int cur = 1;
	for (int i = 0; i < n; i++) {
		if (s.empty() || s.top() != arr[i]) {
			while (true) {
				if (cur > n) {
					cout << "NO\n";
					return 0;
				}
				s.push(cur++);
				res.push_back('+');
				if(s.top() == arr[i]) {
					s.pop();
					res.push_back('-');
					break;
				}
			}
		}
		else if (s.top() == arr[i]) {
			s.pop();
			res.push_back('-');
		}
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\n";
}