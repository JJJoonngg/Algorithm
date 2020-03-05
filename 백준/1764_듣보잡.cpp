/*
����
�������� �赵 ���� ����� ��ܰ�, ���� ���� ����� ����� �־��� ��, �赵 ���� ���� ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �赵 ���� ����� �� N, ���� ���� ����� �� M�� �־�����.
�̾ ��° �ٺ��� N���� �ٿ� ���� �赵 ���� ����� �̸���, N+2° �ٺ��� ���� ���� ����� �̸��� ������� �־�����.
�̸��� ���� ���� ���� �ҹ��ڷθ� �̷������, �� ���̴� 20 �����̴�. N, M�� 500,000 ������ �ڿ����̴�.
3 4
ohhenrie
charlie
baesangwook
abc
obama
baesangwook
ohhenrie
clinton
abc
���
�躸���� ���� �� ����� ���������� ����Ѵ�.
2
baesangwook
ohhenrie
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<string> v, list;
	int n, m;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		string tmp; cin >> tmp;
		if (binary_search(v.begin(), v.end(), tmp)) {
			list.push_back(tmp);
		}
	}
	sort(list.begin(), list.end());
	cout << list.size() << "\n";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << "\n";
	}
}