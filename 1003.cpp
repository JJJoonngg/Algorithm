/*
����
���� �ҽ��� N��° �Ǻ���ġ ���� ���ϴ� C++ �Լ��̴�.

1�� 2�� ��µǰ�, 0�� 1�� ��µȴ�. N�� �־����� ��, fibonacci(N)�� ȣ������ ��,
0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, N�� �־�����. N�� 40���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.
3
0
1
3
���
�� �׽�Ʈ ���̽����� 0�� ��µǴ� Ƚ���� 1�� ��µǴ� Ƚ���� �������� �����ؼ� ����Ѵ�.
1 0
0 1
1 2
*/
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		int dp_zero[41] = { 1,0, };
		int dp_one[41] = { 0,1, };
		for (int i = 2; i < 41; i++) {
			dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
			dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
		}
		cin >> n;
		cout << dp_zero[n] << " " << dp_one[n] << endl;
	}
	return 0;
}
