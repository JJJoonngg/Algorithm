#include <cstdio>
#include <cstdlib>

class Deque {
private:
	typedef struct DlistNode {
		int data;
		struct DlistNode *llink;
		struct DlistNode *rlink;
	}DlistNode;
	typedef struct DequeType {
		DlistNode *head;
		DlistNode *tail;
	}DequeType;
public:
	DlistNode * create_node(DlistNode *link, int item, DlistNode *rlink) {
		DlistNode *node = (DlistNode *)malloc(sizeof(DlistNode));
		if (node == NULL) return;
		node->llink = link;
		node->data = item;
		node->rlink = rlink;
		return node;
	}
	void init(DequeType *dq) {
		dq->head = dq->tail = NULL;
	}
	bool is_empty(DequeType *dq) {
		if (dq->head == NULL) return true;
		else return false;
	}
	void push_front(DequeType *dq, int item) {
		DlistNode *new_node = create_node(NULL, item, dq->head);
		if (is_empty(dq)) dq->tail = new_node;
		else dq->head->llink = new_node;

		dq->head = new_node;
	}
	void push_back(DequeType *dq, int item) {
		DlistNode *new_node = create_node(dq->tail, item, NULL);
		if (is_empty(dq)) dq->head = new_node;
		else dq->tail->rlink = new_node;

		dq->tail = new_node;
	}
	int pop_front(DequeType *dq) {
		int item;
		DlistNode *remove_node;
		if (is_empty(dq)) return;
		else {
			remove_node = dq->head;
			item = remove_node->data;
			dq->head = dq->head->rlink;
			free(remove_node);
			if (dq->head == NULL) dq->tail = NULL;
			else dq->head->llink = NULL;
		}
		return item;
	}
	int pop_back(DequeType *dq) {
		int item;
		DlistNode *remove_node;
		if (is_empty(dq)) return;
		else {
			remove_node = dq->tail;
			item = remove_node->data;
			dq->tail = dq->tail->llink;
			free(remove_node);
			if (dq->tail == NULL) dq->head = NULL;
			else dq->tail->rlink = NULL;
		}
		return item;

	}
	
};