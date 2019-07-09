#define MAXN 101010

/* �ּ� �� ���� */
template <typename T>
struct priority_queue
{
	T arr[MAXN] = { 0 };
	int idx = 1; // ���� �ε����� 1��(1�� �����)

	bool empty() { return idx == 1; };

	int size() { return idx - 1; };


	void push(T data)
	{
		int cur = idx; // ������ �ε��� ����
		arr[idx++] = data; // ���� �������� ������ ����

						   /* upheap => �������� �Էµ� �����͸� root���� �Ž��� �ö󰡸鼭 ������ ��ġ�� ã���ش� */
		while (cur > 1)
		{
			if (arr[cur / 2] > arr[cur]) // ���� �ε����� �θ� �� ũ�� swap
				swap(arr[cur / 2], arr[cur]);
			else break; // �׷��� �ʴٸ� ����
			cur /= 2; // ���� �ε��� <- �θ��� �ε���
		}
	}

	void pop()
	{
		if (empty()) return;
		arr[1] = arr[--idx]; // ���� ������ ��带 root�� �ø� 
		int cur = 1;
		int tmp;

		/* downheap => root�� �ö� ������ ��带 ������ �Ž��� �������鼭 ������ ��ġ�� ã���ش� */
		while (cur * 2 < idx) // �ڽ��� �������� ���� ������ �ݺ�
		{
			tmp = cur;
			if (arr[cur * 2] < arr[tmp]) // ���� �ڽ��� �ڽź��� ������ tmp�� ���� �ڽ�����
				tmp = cur * 2;
			if (cur * 2 + 1 < idx && arr[cur * 2 + 1] < arr[tmp]) // ������ �ڽ��� �����ϰ�, ������ �ڽ��� �ڽź��� ������ tmp�� ������ �ڽ�����
				tmp = cur * 2 + 1;
			if (tmp == cur) break; // tmp == cur�̸� �� �ڽ��� ���� �ڽź��� ũ�ٴ� ���̹Ƿ� downheap ����
			swap(arr[tmp], arr[cur]); // �ڽź��� �� ���� �ڽ��� �־����� swap
			cur = tmp;
		}
	}

	// �ּ����̹Ƿ� ���� ����⿡�� �׻� �ּҰ��� �������
	T top()
	{
		if (idx == 1)
			arr[1] = 0;
		return arr[1];
	}
};