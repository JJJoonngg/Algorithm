/*
�ð����� 2��
����
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1��N��100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����.
���� �ٿ��� M(1��M��100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� �������� ������ int �� �Ѵ�.
5
4 1 5 2 3
5
1 3 7 9 5
���
M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.
1
1
0
0
1
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N, M;
void bfs(int start, int end, int data) {
	int mid = (start + end) / 2;
	if (start > end) {
		printf("0\n");
	}
	else {
		if (v[mid] == data) {
			printf("1\n");
			return;
		}
		else if (data > v[mid]) {
			start = mid + 1;
			bfs(start, end, data);
		}
		else if (data < v[mid]) {
			end = mid - 1;
			bfs(start, end, data);
		}
	}
}
int main() {
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int data;
		scanf("%d", &data);
		bfs(0, N - 1, data);
	}
	return 0;
}
