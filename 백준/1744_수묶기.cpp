/*
https://www.acmicpc.net/problem/1744
����
���̰� N�� ������ �־����� ��, �� ������ ���� ���Ϸ��� �Ѵ�. ������, �׳� �� ������ ���� ��� ���ؼ� ���ϴ� ���� �ƴ϶�,
������ �� ���� �������� �Ѵ�. � ���� �������� �� ��, ��ġ�� ������� ���� �� �ִ�. ������, ���� ��ġ�� �ִ� ��(�ڱ� �ڽ�)�� ���� ���� �Ұ����ϴ�.
�׸��� � ���� ���� �Ǹ�, ������ ���� ���� �� ���� ���� ���� ���� �Ŀ� ���Ѵ�.
���� ���, � ������ {0, 1, 2, 4, 3, 5}�� ��, �׳� �� ������ ���� ���ϸ� 0+1+2+4+3+5 = 15�̴�.
������, 2�� 3�� ����, 4�� 5�� ���� �Ǹ�, 0+1+(2*3)+(4*5) = 27�� �Ǿ� �ִ밡 �ȴ�.
������ ��� ���� �� �ѹ��� ���ų�, �ƴϸ� ���� �ʾƾ��Ѵ�.

������ �־����� ��, ������ �� ���� ������ ������ ��, �� ���� �ִ밡 �ǰ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. N�� 10,000���� �۴�. ��° �ٺ��� N���� �ٿ�, ������ �� ���� �־�����.
������ ���� -10,000���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̴�.
4
-1
2
1
3
���
���� ������ ���� �� ���� �ִ��� ����Ѵ�. ������ �׻� 2^31���� �۴�.
6
*/
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int> positive;
	priority_queue<int, vector<int>, greater<int>>negative;
	int n, sum = 0, zero = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp == 1) sum++;
		else if (tmp > 0) positive.push(tmp);
		else if (tmp < 0) negative.push(tmp * (-1));
		else zero++;
	}
	if (positive.size() % 2 == 1) positive.push(1);
	if (negative.size() % 2 == 1) {
		if (!zero) 	sum += negative.top() * (-1);
		negative.pop();
	}
	int psiz = positive.size(), nsiz = negative.size();
	for (int i = 0; i < psiz / 2; i++) {
		int tmp = positive.top(); positive.pop();
		sum += tmp * positive.top();
		positive.pop();
	}

	for (int i = 0; i < nsiz / 2; i++) {
		int tmp = negative.top(); negative.pop();
		sum += tmp * negative.top();
		negative.pop();
	}

	cout << sum << "\n";
}