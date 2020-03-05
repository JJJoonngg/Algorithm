#define MAXN 101010

/* 최소 힙 구현 */
template <typename T>
struct priority_queue
{
	T arr[MAXN] = { 0 };
	int idx = 1; // 시작 인덱스를 1로(1이 꼭대기)

	bool empty() { return idx == 1; };

	int size() { return idx - 1; };


	void push(T data)
	{
		int cur = idx; // 마지막 인덱스 저장
		arr[idx++] = data; // 힙의 마지막에 데이터 삽입

						   /* upheap => 마지막에 입력된 데이터를 root까지 거슬러 올라가면서 적절한 위치를 찾아준다 */
		while (cur > 1)
		{
			if (arr[cur / 2] > arr[cur]) // 현재 인덱스의 부모가 더 크면 swap
				swap(arr[cur / 2], arr[cur]);
			else break; // 그렇지 않다면 종료
			cur /= 2; // 현재 인덱스 <- 부모의 인덱스
		}
	}

	void pop()
	{
		if (empty()) return;
		arr[1] = arr[--idx]; // 힙의 마지막 노드를 root로 올림 
		int cur = 1;
		int tmp;

		/* downheap => root로 올라간 마지막 노드를 밑으로 거슬러 내려가면서 적절한 위치를 찾아준다 */
		while (cur * 2 < idx) // 자식이 존재하지 않을 때까지 반복
		{
			tmp = cur;
			if (arr[cur * 2] < arr[tmp]) // 왼쪽 자식이 자신보다 작으면 tmp를 왼쪽 자식으로
				tmp = cur * 2;
			if (cur * 2 + 1 < idx && arr[cur * 2 + 1] < arr[tmp]) // 오른쪽 자식이 존재하고, 오른쪽 자식이 자신보다 작으면 tmp를 오른쪽 자식으로
				tmp = cur * 2 + 1;
			if (tmp == cur) break; // tmp == cur이면 두 자식이 전부 자신보다 크다는 뜻이므로 downheap 종료
			swap(arr[tmp], arr[cur]); // 자신보다 더 작은 자식이 있었으면 swap
			cur = tmp;
		}
	}

	// 최소힙이므로 힙의 꼭대기에는 항상 최소값이 들어있음
	T top()
	{
		if (idx == 1)
			arr[1] = 0;
		return arr[1];
	}
};