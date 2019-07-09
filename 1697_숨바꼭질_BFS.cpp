/*
����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, 
������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�. 
����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. 
�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.
5 17
���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
4

��Ʈ
�����̰� 5-10-9-18-17 ������ ���� 4�ʸ��� ������ ã�� �� �ִ�.
*/
#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 100001
using namespace std;
int N, K;
int visit[MAX];
queue<int> position;
int bfs(int n, int k) {
	int time = 0;
	position.push(n);
	while (1) {
		int siz = position.size();
		for (int i = 0; i < siz; i++) {
			int tmp = position.front();
			position.pop();

			if (tmp == k) return time;

			if (tmp > 0 && !visit[tmp - 1]) {
				position.push(tmp - 1);
				visit[tmp - 1] = true;
			}
			if (tmp < 100000 && !visit[tmp + 1]) {
				position.push(tmp + 1);
				visit[tmp + 1] = true;
			}
			if (tmp * 2 <= 100000 && !visit[tmp * 2]) {
				position.push(tmp * 2);
				visit[tmp * 2] = true;
			}
		}
		time++;
	}
}
int main() {
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs(N, K));
	return 0;
}