/*
https://www.acmicpc.net/problem/1620
�Է�
ù° �ٿ��� ������ ���ϵǾ� �ִ� ���ϸ��� ���� N�̶� ���� ����� �ϴ� ������ ���� M�� �־���.
N�� M�� 1���� ũ�ų� ����, 100,000���� �۰ų� ���� �ڿ����ε�, �ڿ����� ������ ����? �𸣸� ������� ������. ���� �������� ������ ������ �غ� �Ǿ��־�.

��° �ٺ��� N���� �ٿ� ���ϸ��� ��ȣ�� 1���� ���ϸ���� N���� �ش��ϴ� ���ϸ���� �� �ٿ� �ϳ��� �Է����� ����.
���ϸ��� �̸��� ��� ����θ� �̷�����ְ�, ��, ��... ù ���ڸ� �빮���̰�, ������ ���ڴ� �ҹ��ڷθ� �̷���� �־�. 
���ϸ� �̸��� �ִ� ���̴� 20�̾�. �� ���� �ٺ��� �� M���� �ٿ� ���� ������ϴ� ������ �Է����� ����. 
������ ���ĺ����θ� ������ ���ϸ� ��ȣ�� ���ؾ� �ϰ�, ���ڷθ� ������, ���ϸ� ��ȣ�� �ش��ϴ� ���ڸ� ����ؾ���. 
�Է����� ������ ���ڴ� �ݵ�� 1���� ũ�ų� ����, N���� �۰ų� ����, �Է����� ������ ���ڴ� �ݵ�� ������ �ִ� ���ϸ��� �̸��� �־���. �׷� ȭ����!!!
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
25
Raichu
3
Pidgey
Kakuna
���
ù° �ٺ��� ���ʴ�� M���� �ٿ� ������ ������ ���� ���� ���������� ���ھ�!!!. �Է����� ���ڰ� ���Դٸ� �� ���ڿ� �ش��ϴ� ���ϸ��� �̸���,
���ڰ� �������� �� ���ϸ��� �̸��� �ش��ϴ� ��ȣ�� ����ϸ� ��. �׷� ��ť~
Pikachu
26
Venusaur
16
14
*/
#include <iostream>
#include <string>
#include <map>
#define MAXI 100000 + 1
using namespace std;
string pocket[MAXI];
map<string, int> book;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		pocket[i] = tmp;
		book.insert(make_pair(tmp, i));
	}
	for (int i = 0; i < m; i++) {
		char tmp; string s;
		cin >> s;	 tmp = s[0];
		if (tmp >= '0' && tmp <= '9') {
			int num = 0;
			for (int i = 0; s[i] != 0; i++) {
				num *= 10;
				num += s[i] - '0';
			}
			cout << pocket[num - 1] << "\n";
		}
		else {
			int res = book[s] + 1;
			cout << res << "\n";
		}
	}
}