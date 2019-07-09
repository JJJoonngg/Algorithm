/*
����
���밪 ���� ������ ���� ������ �����ϴ� �ڷᱸ���̴�.

�迭�� ���� x (x �� 0)�� �ִ´�.
�迭���� ���밪�� ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
���밪�� ���� ���� ���� �������� ����, ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.

�Է�
ù° �ٿ� ������ ���� N(1��N��100,000)�� �־�����. ���� N���� �ٿ��� ���꿡 ���� ������ ��Ÿ���� ���� x�� �־�����.
���� x�� 0�� �ƴ϶�� �迭�� x��� ���� �ִ�(�߰��ϴ�) �����̰�,
x�� 0�̶�� �迭���� ���밪�� ���� ���� ���� ����ϰ� �� ���� �迭���� �����ϴ� ����̴�. �ԷµǴ� ������ -231���� ũ��, 231���� �۴�.
18
1
-1
0
0
0
1
1
-1
-1
2
-2
0
0
0
0
0
0
0
���
�Է¿��� 0�� �־��� ȸ����ŭ ���� ����Ѵ�. ���� �迭�� ��� �ִ� ����ε� ���밪�� ���� ���� ���� ����϶�� �� ��쿡�� 0�� ����ϸ� �ȴ�.
-1
1
0
-1
-1
1
1
-2
2
0
*/
#include <cstdio>
#include <stdbool.h>
using namespace std;
#define MAX 100001
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX];
	int heap_size;
}HeapType;

void init(HeapType *h) {
	h->heap_size = 0;
}
bool is_empty(HeapType *h) {
	if (h->heap_size == 0) return true;
	else return false;
}

void insertMinHeap(HeapType *h, element	item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element deleteMinHeap(HeapType *h) {
	int parent, child;
	element item, tmp;
	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (tmp.key <= h->heap[child].key)break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	return item;
}

int main() {
	HeapType positiveHeap;
	HeapType negativeHeap;
	init(&positiveHeap);
	init(&negativeHeap);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		element data;
		data.key = x;
		if (x < 0) {
			data.key *= (-1);
			insertMinHeap(&negativeHeap, data);
		}
		else if (x > 0)
			insertMinHeap(&positiveHeap, data);

		else if (x == 0) {
			if (is_empty(&positiveHeap) && is_empty(&negativeHeap)) {
				printf("0\n");
			}
			else if (is_empty(&positiveHeap) && (!is_empty(&negativeHeap))) {
				element tmp_negative = deleteMinHeap(&negativeHeap);
				int negative = (-1)*tmp_negative.key;
				printf("%d\n", negative);
			}
			else if ((!is_empty(&positiveHeap)) && is_empty(&negativeHeap)) {
				printf("%d\n", deleteMinHeap(&positiveHeap));
			}
			else {
				element tmp_positive = deleteMinHeap(&positiveHeap);
				element tmp_negative = deleteMinHeap(&negativeHeap);
				int negative = (-1)*tmp_negative.key;

				if (tmp_positive.key == tmp_negative.key) {
					printf("%d\n", negative);
					insertMinHeap(&positiveHeap, tmp_positive);
				}
				else if (tmp_positive.key >= tmp_negative.key) {
					printf("%d\n", negative);
					insertMinHeap(&positiveHeap, tmp_positive);
				}
				else if (tmp_positive.key <= tmp_negative.key) {
					printf("%d\n", tmp_positive.key);
					insertMinHeap(&negativeHeap, tmp_negative);
				}
			}
		}
	}
	return 0;
}