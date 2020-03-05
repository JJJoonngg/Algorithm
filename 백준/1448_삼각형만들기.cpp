/*
����
�����̴� N���� ���븦 ������ �ִ�. N���� ���� �߿� 3���� ���븦 �������� ��, 
�� ����� �ﰢ���� ���� �� �ִٸ�, �� ���� ������ ���� �ִ밪�� ���ϰ� �ʹ�.

�Է�
ù° �ٿ� ������ ���� N�� �־�����. N�� 3���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �ڿ����̴�. 
��° �ٿ� ������ ���̰� ������ ���̿� �ΰ� �־�����. ������ ���̴� 1,000,000���� �۰ų� ����.
3
1
2
3

���
ù° �ٿ� �ﰢ�� �� ���� ������ ���� �ִ밪�� ����Ѵ�. 
���� �ﰢ���� ���� �� ������ -1�� ����Ѵ�.
-1
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int max = -1;
	cin >> N;

	int* straw = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> straw[i];
	}
	
	sort(straw, straw + N);
	
	for (int i = 0; i <N-2; i++) {
		if (straw[i + 2] < straw[i] + straw[i + 1]) {
			max = straw[i + 2] + straw[i] + straw[i + 1];
		}
	}
	cout << max << endl;


	delete[] straw;
	return 0;
}