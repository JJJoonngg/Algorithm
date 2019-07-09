/*
����
�θ� �� �˷��� �ڷᱸ�� �� �ּ� ���̶�� ���� �ִ�. �ּ� ���� �̿��Ͽ� ������ ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�迭�� �ڿ��� x�� �ִ´�.
�迭���� ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.
�Է�
ù° �ٿ� ������ ���� N(1��N��100,000)�� �־�����. ���� N���� �ٿ��� ���꿡 ���� ������ ��Ÿ���� ���� x�� �־�����. 
���� x�� �ڿ������ �迭�� x��� ���� �ִ�(�߰��ϴ�) �����̰�, x�� 0�̶�� �迭���� ���� ���� ���� ����ϰ� �� ���� �迭���� �����ϴ� ����̴�. 
�ԷµǴ� �ڿ����� 2^31���� �۴�.
9
0
12345678
1
2
0
0
0
0
32
���
�Է¿��� 0�� �־��� ȸ����ŭ ���� ����Ѵ�. ���� �迭�� ��� �ִ� ����ε� ���� ���� ���� ����϶�� �� ��쿡�� 0�� ����ϸ� �ȴ�.
0
1
2
12345678
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
	HeapType heap;
	init(&heap);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (x != 0) {
			element e;
			e.key = x;
			insertMinHeap(&heap, e);
		}
		else if ((x == 0) && (!is_empty(&heap))) {
			printf("%d\n", deleteMinHeap(&heap));
		}
		else if ((x == 0) && (is_empty(&heap))) {
			printf("0\n");
		}
	}
	return 0;
}