/*
����
IQ Test�� ���� �߿��� ����� ������ ã�� ������ �ִ�. ������ ������ �־����� ��, ���� ���� ã�� �����̴�.
���� ���, 1, 2, 3, 4, 5�� �־�����. ���� ���ڴ� �����ΰ�? �翬�� ���� 6�̴�. 
�ణ �� ����� ������ ����, 3, 6, 12, 24, 48�� �־����� ��, ���� ���ڴ� �����ΰ�? ���� ���� 96�̴�.
���� ���� ����� ������ ����.
1, 4, 13, 40�� �־����� ��, ���� ���ڴ� �����ϱ�? ���� 121�̴�. �� ������ �׻� ���� ���� �� ��*3+1�̱� �����̴�.
�����̴� ���� 3������ ��� Ǯ�� �������Ƿ�, �ڵ����� Ǯ���ִ� ���α׷��� �ۼ��ϱ�� �ߴ�. 
�׻� ��� ���� ���ϴ� ��Ģ�� �� ��*a + b�̴�. �׸���, a�� b�� �����̴�.
�� N���� �־����� ��, ��Ģ�� �´� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N���� ���� �־�����. �� ���� ��� ������ 100���� �۰ų� ���� �����̴�.
4
1 4 13 40

���
���� ���ڸ� ����Ѵ�. ���� ���� ���ڰ� ���� ���� ��쿡�� A�� ����ϰ�, ���� ���ڸ� ���� �� ���� ��쿡�� B�� ����Ѵ�.
121
*/
#include <iostream>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	int N;
	cin >> N;
	int* number = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	if (N == 1) {
		cout << "A" << endl;
	}
	else if (N == 2) {
		if (number[0] == number[1]) {
			cout << number[0] << endl;
		}
		else {
			cout << "A" << endl;
		}
	}
	else if(N >= 3){
		int check = 1;
		int first = number[0];
		int second = number[1];
		int third = number[2];
		
		if (second == first) {
			a = 0;
			b = second;
		}
		else {
			a = (third - second) / (second - first);
			b = second - (first * a);
		}

		for(int i=0;i<N-1;i++){
			
			int checkValue = number[i] * a + b;
			int checkNextValue = number[i + 1];

			if (!(checkValue == checkNextValue)) {
				check = 0;
			}
		}
	
		if (check == 1) {
			int nextValue = number[N - 1] * a + b;
			cout << nextValue << endl;
		}
		if (check == 0) {
			cout << "B" << endl;
		}
		
	}

	delete[] number;
	return 0;
}