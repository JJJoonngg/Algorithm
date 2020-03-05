/*
https://www.acmicpc.net/problem/5052
����
��ȭ��ȣ ����� �־�����. �̶�, �� ����� �ϰ����� �ִ��� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

��ȭ��ȣ ����� �ϰ����� �����Ϸ���, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ����� �Ѵ�.

���� ���, ��ȭ��ȣ ����� �Ʒ��� ���� ��츦 �����غ���

�����ȭ: 911
���: 97 625 999
����: 91 12 54 26
�� ��쿡 �����̿��� ��ȭ�� �� �� �ִ� ����� ����. ��ȭ�⸦ ��� ������ ��ȣ�� ó�� �� �ڸ��� ������ ���� �ٷ� �����ȭ�� �ɸ��� �����̴�.
����, �� ����� �ϰ����� ���� ����̴�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t�� �־�����. (1 �� t �� 50) �� �׽�Ʈ ���̽��� ù° �ٿ��� ��ȭ��ȣ�� �� n�� �־�����. (1 �� n �� 10000)
���� n���� �ٿ��� ��Ͽ� ���ԵǾ� �ִ� ��ȭ��ȣ�� �ϳ��� �־�����. ��ȭ��ȣ�� ���̴� ���� 10�ڸ��̸�, ��Ͽ� �ִ� �� ��ȭ��ȣ�� ���� ���� ����.
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
���
�� �׽�Ʈ ���̽��� ���ؼ�, �ϰ��� �ִ� ����� ��쿡�� YES, �ƴ� ��쿡�� NO�� ����Ѵ�.
NO
YES
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 11111
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		string arr[MAX];
		bool flag = true;
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			arr[i] = tmp;
		}
		sort(arr, arr + n);
		for (int i = 0; i < n - 1; i++) {
			if (arr[i].length() < arr[i + 1].length()) {
				const char* tmp1 = arr[i].c_str();
				const char* tmp2 = arr[i + 1].c_str();
				if (!strncmp(tmp1, tmp2, arr[i].length())) {
					flag = false; break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}