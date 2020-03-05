/*
https://www.acmicpc.net/problem/10814
����
�¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����. �̶�, ȸ������ ���̰� �����ϴ� ������,
���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)

��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����. 
���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� �����̰�, �̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, 
���̰� 100���� �۰ų� ���� ���ڿ��̴�. �Է��� ������ ������ �־�����.
3
21 Junkyu
21 Dohyun
20 Sunyoung
���
ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, ���̰� ������ ������ ������ �� �ٿ� �� �� ���̿� �̸��� �������� ������ ����Ѵ�.
20 Sunyoung
21 Junkyu
21 Dohyun
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct info { int old; string name; int num; };
vector<info> v;
bool comp(const info &tmp1,const info &tmp2) {
	if (tmp1.old == tmp2.old) return tmp1.num < tmp2.num;
	else return tmp1.old < tmp2.old;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { 
		cin >> v[i].old >> v[i].name; 
		v[i].num = i; 
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++)
		cout << v[i].old << " " << v[i].name << "\n";
}