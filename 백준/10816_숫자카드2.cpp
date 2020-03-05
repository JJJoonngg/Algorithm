/*
https://www.acmicpc.net/problem/10816
����
���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. ����̴� ���� ī�� N���� ������ �ִ�.
���� M���� �־����� ��, �� ���� �����ִ� ���� ī�带 ����̰� �� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����̰� ������ �ִ� ���� ī���� ���� N(1 �� N �� 500,000)�̰� �־�����.
��° �ٿ��� ���� ī�忡 �����ִ� ������ �־�����. ���� ī�忡 �����ִ� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.

��° �ٿ��� M(1 �� M �� 500,000)�� �־�����. ��° �ٿ��� ����̰� �� �� ������ �ִ� ���� ī������ ���ؾ� �� M���� ������ �־�����,
�� ���� �������� ���еǾ��� �ִ�. �̼��� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
���
ù° �ٿ� �Է����� �־��� M���� ���� ���ؼ�, �� ���� ���� ���� ī�带 ����̰� �� �� ������ �ִ����� �������� ������ ����Ѵ�.
3 0 0 1 2 0 0 2

�˰��� �з� : �̺�Ž��
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v;
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	ans.push_back(make_pair(v[0], 1));
	int idx = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == ans[idx].first) ans[idx].second++;
		else {
			ans.push_back(make_pair(v[i], 1));
			idx++;
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		int start = 0, end = ans.size() - 1;
		bool check = false;
		int res = 0;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (ans[mid].first == tmp) {
				check = true;
				res = ans[mid].second;
				break;
			}
			else if (ans[mid].first > tmp) end = mid - 1;
			else start = mid + 1;
		}
		if (check) cout << res << " ";
		else cout << "0 ";
	}
	cout << "\n";
}