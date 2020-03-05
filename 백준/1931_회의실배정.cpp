/*
https://www.acmicpc.net/problem/1931
����
�� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǵ鿡 ���Ͽ� ȸ�ǽ� ���ǥ�� ������� �Ѵ�.
�� ȸ�� I�� ���� ���۽ð��� ������ �ð��� �־��� �ְ�, �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� �ִ���� ȸ�Ǹ� ã�ƶ�.
��, ȸ�Ǵ� �ѹ� �����ϸ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�.
ȸ���� ���۽ð��� ������ �ð��� ���� ���� �ִ�. �� ��쿡�� �������ڸ��� ������ ������ �����ϸ� �ȴ�.

�Է�
ù° �ٿ� ȸ���� �� N(1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N+1 �ٱ��� �� ȸ���� ������ �־����µ�
�̰��� ������ ���̿� �ΰ� ȸ���� ���۽ð��� ������ �ð��� �־�����. ���� �ð��� ������ �ð��� 2^31-1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
���
ù° �ٿ� �ִ� ����� �� �ִ� ȸ�� ���� ����Ͽ���.
4

��Ʈ
(1,4), (5,7), (8,11), (12,14) �� �̿��� �� �ִ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct time { int start; int end; };
bool judge(time a, time b) {
	if (a.end != b.end) return a.end < b.end;
	else return a.start < b.start;
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	std:ios::sync_with_stdio(false);
	int n;  cin >> n;
	vector<time> v(n);

	for (int i = 0; i < n; i++) 
		cin >> v[i].start >> v[i].end;

	sort(v.begin(), v.end(), judge);
	int cnt = 0, tmp = 0;

	for (int i = 0; i < n; i++) {
		if (v[i].start >= tmp) {
			tmp = v[i].end;
			cnt++;
		}
	}
	cout << cnt << "\n";
}