/*
문제
절대값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

배열에 정수 x (x ≠ 0)를 넣는다.
배열에서 절대값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
절대값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고,
x가 0이라면 배열에서 절대값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.
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
출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절대값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.
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