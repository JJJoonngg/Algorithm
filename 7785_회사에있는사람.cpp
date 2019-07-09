/*
https://www.acmicpc.net/problem/7785
����
����̴� �������� ����Ʈ���� ȸ�� ��ۿ��� ���Ѵ�. �� ȸ���� ���� ū Ư¡�� �����ο� ����� �ð��̴�.
����, �������� �ݵ�� 9�ú��� 6�ñ��� ȸ�翡 ���� �ʾƵ� �ȴ�.
�� ������ �ڱⰡ ���� �� ����� �� �ְ�, �ƹ����� ����� �� �ִ�.
����̴� ��� ����� ����ī�� �ý����� �α׸� ������ �ִ�. �� �α״� � ����� ȸ�翡 ���Դ���, ���������� ��ϵǾ��� �ִ�.
�αװ� �־����� ��, ���� ȸ�翡 �ִ� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �α׿� ��ϵ� ���� ����� �� n�� �־�����. (2 �� n �� 10^6) ���� n���� �ٿ��� ���� ����� ������� �־�����,
�� ����� �̸��� �־����� "enter"�� "leave"�� �־�����. "enter"�� ���� ���, "leave"�� ���� ����̴�.

ȸ�翡�� ���������� ������, ��ҹ��ڰ� �ٸ� ��쿡�� �ٸ� �̸��̴�. ������� �̸��� ���ĺ� ��ҹ��ڷ� ������ 5���� ������ ���ڿ��̴�.
4
Baha enter
Askar enter
Baha leave
Artem enter
���
���� ȸ�翡 �ִ� ����� �̸��� ���� ���� �������� �� �ٿ� �� �� ����Ѵ�.
Askar
Artem
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<string> v;
	set<string> s;
	while (n--) {
		string name, info;
		cin >> name >> info;
		if (info == "enter") s.insert(name);
		else s.erase(name);		
	}
	for (auto it = s.begin(); it != s.end(); it++)
		v.push_back(*it);
	sort(v.begin(), v.end(), greater<string>());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}