/*
�Է�
�Է��� ù° �ٿ� �� ����� ����� �ϴ� ���� �� N�� �־�����. (5��N��100,000)
�� �� N���� �ٿ� ����̿� �Լ��̰� ���ϴ� �ڿ���(<5,000,000)�� �������� ���еǾ� �־�����.
5
2 3
4 9
2 10
7 37
11 3
���
����̰� �̱� ��� ���Ҽ��� �� ������� �Լ��̰� �̱� ��� ���Ҽ� ������ ���Լ����� ����Ѵ�.
���� ��� ��� ���쿭�� ���� �� ������ �� ����Ѵ�.
\�Ҽ��� �� �����
*/
#include <iostream>
#include <queue>
#include <cmath>
#define MAXI 5000000 + 1
using namespace std;
bool num[MAXI] = { 0, };
bool prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0) return false;
	return true;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	priority_queue<int> pqD, pqG;
	long long resD = 0, resG = 0;
	int n; cin >> n;
	while (n--) {
		int inputD, inputG;
		cin >> inputD >> inputG;
		if (!prime(inputD)) {
			if (pqG.size() < 3) resG += 1000;
			else {
				int tmp1 = pqG.top(); pqG.pop();
				int tmp2 = pqG.top(); pqG.pop();
				int tmp3 = pqG.top(); pqG.pop();
				resG += tmp3;
				pqG.push(tmp1);	pqG.push(tmp2); pqG.push(tmp3);
			}
		}
		else {
			if (num[inputD]) resD -= 1000;
			else {
				num[inputD] = true;
				pqD.push(inputD);
			}
		}
		if (!prime(inputG)) {
			if (pqD.size() < 3) resD += 1000;
			else {
				int tmp1 = pqD.top(); pqD.pop();
				int tmp2 = pqD.top(); pqD.pop();
				int tmp3 = pqD.top(); pqD.pop();
				resD += tmp3;
				pqD.push(tmp1);	pqD.push(tmp2); pqD.push(tmp3);
			}
		}
		else{
			if (num[inputG]) resG -= 1000;
			else {
				num[inputG] = true;
				pqG.push(inputG);
			}
		}
	}
	if (resD == resG) cout << "�쿭�� ���� �� ����\n";
	else if (resD > resG) cout << "�Ҽ��� �� �����\n";
	else cout << "�Ҽ� ������ ���Լ�\n";
}