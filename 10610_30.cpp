/*
https://www.acmicpc.net/problem/10610
����
�����, �̸��ڴ� �쿬�� ��Ÿ����� ��� N�� ���Ҵ�. �̸��ڴ� 30�̶� ���� �����ϱ� ������,
�״� ��Ÿ����� ã�� ���� ���Ե� ���ڵ��� ���� 30�� ����� �Ǵ� ���� ū ���� ����� �;��Ѵ�.

�̸��ڸ� ���� �װ� ����� �;��ϴ� ���� ����ϴ� ���α׷��� �ۼ��϶�.

�Է�
N�� �Է¹޴´�. N�� �ִ� 10^5���� ���ڷ� �����Ǿ� ������, 0���� �������� �ʴ´�.
30
102
2931
���
�̸��ڰ� ����� �;��ϴ� ���� �����Ѵٸ� �� ���� ����϶�. �� ���� �������� �ʴ´ٸ�, -1�� ����϶�.
30
210
-1
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXI 100001
using namespace std;
char arr[MAXI] = { 0, };
long long sum = 0;
bool check = false;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> arr; int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		if (arr[i] == '0')	check = true;
		sum += arr[i];
	}
	if (!check) cout << "-1\n";
	else {
		sort(arr, arr + len);
		if (!(sum % 3)) {
			for (int i = len - 1; i >= 0; i--) 
				cout << arr[i];
			cout << "\n";
		}
		else cout << "-1\n";
	}
}