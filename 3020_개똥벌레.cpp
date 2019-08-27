/*
����
���˹��� �� ������ ��ֹ�(������ ������)�� ������ ������ ����. ������ ���̴� N�����̰�, ���̴� H�����̴�. 
(N�� ¦��) ù ��° ��ֹ��� �׻� �����̰�, �� �������� �������� ������ �����ư��鼭 �����Ѵ�.

������ ũ��� ����, ��� ��ֹ��� ũ�Ⱑ �־�����. 
�̶�, ���˹����� �ı��ؾ��ϴ� ��ֹ��� �ּڰ��� �׷��� ������ �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� H�� �־�����. N�� �׻� ¦���̴�. (2 �� N �� 200,000, 2 �� H �� 500,000)
���� N�� �ٿ��� ��ֹ��� ũ�Ⱑ ������� �־�����. ��ֹ��� ũ��� H���� ���� ����̴�.
14 5
1
3
4
2
2
4
3
4
3
3
3
2
3
3
���
ù° �ٿ� ���˹����� �ı��ؾ� �ϴ� ��ֹ��� �ּڰ��� �׷��� ������ ���� �������� �����Ͽ� ����Ѵ�.
7 2
�˰��� �з�: ����, �̺� Ž��
*/
#include <bits/stdc++.h>
#define INF 1e9
#define MAXI 500000 + 1
using namespace std;
int bottom[MAXI], top[MAXI];
int n, h, res = INF, tmp, cnt = 1;
int inputBottom, inputTop, maxBottom = 0, maxTop = 0;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++) {
		cin >> inputBottom >> inputTop;
		bottom[inputBottom]++;
		top[inputTop]++;
		maxBottom = max(maxBottom, inputBottom);
		maxTop = max(maxTop, inputTop);
	}
	for (int i = maxBottom; i >= 1; i--) bottom[i] += bottom[i + 1];
	for (int i = maxTop; i >= 1; i--) top[i] += top[i + 1];
	
	for (int i = 1; i <= h; i++) {
		int tmp = bottom[i] + top[h - i + 1];
		if (res > tmp) cnt = 1, res = tmp;
		else if (res == tmp) cnt++;
	}
	cout << res << " " << cnt << "\n";
}