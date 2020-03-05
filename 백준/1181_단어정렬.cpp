/*
https://www.acmicpc.net/problem/1181
����
���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���̰� ª�� �ͺ���
���̰� ������ ���� ������
�Է�
ù° �ٿ� �ܾ��� ���� N�� �־�����. (1��N��20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
���
���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> v;
bool compare(string s1,string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	else
		return s1.length() < s2.length();
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n - 1; i++) {
		if (v[i].length() == v[i + 1].length() && v[i] == v[i + 1]) continue;
		cout << v[i] << "\n";
	}
	cout << v[n - 1] << "\n";
}