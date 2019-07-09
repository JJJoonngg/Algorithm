/*
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.
5
5
4
3
2
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
using namespace std;
struct compare { bool operator()(int& l, int &r) { return l > r; } };
int main() {
	int n;
	priority_queue<int, vector<int>, compare> pq;
	scanf("%d", &n);
	while(n--){
		int tmp;
		scanf("%d", &tmp);
		pq.push(tmp);
	}
	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}
	return 0;
}