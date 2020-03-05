/*
https://www.acmicpc.net/problem/2562
����
9���� ���� �ٸ� �ڿ����� �־��� ��, �̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� �ٸ� 9���� �ڿ���

3, 29, 38, 12, 57, 74, 40, 85, 61

�� �־�����, �̵� �� �ִ��� 85�̰�, �� ���� 8��° ���̴�.

�Է�
ù ° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� �ϳ��� �ڿ����� �־�����. �־����� �ڿ����� 100 ���� �۴�.
3
29
38
12
57
74
40
85
61
���
ù° �ٿ� �ִ��� ����ϰ�, ��° �ٿ� �ִ��� �� ��° �������� ����Ѵ�.
85
8
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
bool comp(pair<int, int> &tmp1, pair<int, int> &tmp2) { return tmp1.first < tmp2.first; }
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		int tmp; cin >> tmp;
		v.push_back({ tmp,i + 1 });
	}
	sort(v.begin(), v.end(), comp);
	cout << v.back().first<< "\n";
	cout << v.back().second<< "\n";
}