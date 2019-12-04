/*
����
�ٷ� ���� �ֹ��� ������ �� ���踦 �ָӴϿ� ���� ä �����ϰ� ����� �� ������ Ȳ���� ��Ȳ�� ������ ��������, 702ȣ�� ���ο� ���� �ý����� ��ġ�ϱ�� �Ͽ���.
�� ���� �ý����� ���谡 �ƴ� ��ȣ�� �����ϰ� �Ǿ� �ִ� �ý����̴�.

��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ������ �ּ� �� ���� �������� �����Ǿ� �ִٰ� �˷��� �ִ�.
���� ���ĵ� ���ڿ��� ��ȣ�ϴ� �������� �������� �̷�� ���� ��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ��� ���̶�� �����ȴ�.
��, abc�� ���ɼ��� �ִ� ��ȣ������ bac�� �׷��� �ʴ�.

�� ���� �ý��ۿ��� �������� ��ȣ�� ������� ���� ������ ������ C������ �ִٰ� �Ѵ�.
�� ���ĺ��� �Լ��� �ν�, ���� ������ �������� �濡 ħ���ϱ� ���� ��ȣ�� ������ ������ �Ѵ�.
C���� ���ڵ��� ��� �־����� ��, ���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� L, C�� �־�����. (3 �� L �� C �� 15) ���� �ٿ��� C���� ���ڵ��� �������� ���еǾ� �־�����.
�־����� ���ڵ��� ���ĺ� �ҹ����̸�, �ߺ��Ǵ� ���� ����.
4 6
a t c i s w
���
�� �ٿ� �ϳ���, ���������� ���ɼ� �ִ� ��ȣ�� ��� ����Ѵ�.
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> res;
int L, C;
bool visit[27];
char alphabet[15];
void dfs(int now, int cnt, string s) {
	if (cnt == L) {
		int consonanat = 0;
		int vowel = 0;
		for (int i = 0; i < s.length(); i++) {
			int tmp = s[i] - 'a';
			if (tmp == 0 || tmp == 4 || tmp == 8 || tmp == 14 || tmp == 20) vowel++;
			else consonanat++;
		}
		sort(s.begin(), s.end());
		if (vowel > 0 && consonanat > 1) res.push_back(s);
	}
	else {
		for (int i = now + 1; i < C; i++) {
			if (!visit[alphabet[i] - 'a']) {
				visit[alphabet[i] - 'a'] = true;
				dfs(i, cnt + 1, s + alphabet[i]);
				visit[alphabet[i] - 'a'] = false;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> alphabet[i];
	sort(alphabet, alphabet + C);
	for (int i = 0; i < C ; i++) {
		visit[alphabet[i] - 'a'] = true;
		string tmp = "";
		tmp += alphabet[i];
		dfs(i, 1, tmp);
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
}