/*
����
�������� ž������ �����̴�. �������� ���뿡�� ����� �ϴ� �����̴�.
�������� �׳� �ٹ��� ���� �Ŀ�, ���� �Ǹ��� å�� ������ ���鼭 ���� ���� �ȸ� å�� ������ ĥ�ǿ� ����� �ϵ� ���� �ϰ� �ִ�.

���� �Ϸ� ���� �ȸ� å�� ������ �Է����� ������ ��, ���� ���� �ȸ� å�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� �Ϸ� ���� �ȸ� å�� ���� N�� �־�����. �� ���� 1,000���� �۰ų� ���� �ڿ����̴�.
��°���� N���� �ٿ� å�� ������ �Է����� ���´�. å�� ������ ���̴� 50���� �۰ų� ����, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.
5
top
top
top
top
kimtop
���
ù° �ٿ� ���� ���� �ȸ� å�� ������ ����Ѵ�. ���� ���� ���� �ȸ� å�� ���� ���� ��쿡�� ���� ������ ���� �ռ��� ������ ����Ѵ�.
top

�˰��� �з�
Ž��
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct info { string input; int siz; };
vector<info> v;
bool comp(info tmp1, info tmp2) { 
	if (tmp1.siz == tmp2.siz)return tmp1.input < tmp2.input;
	else return tmp1.siz > tmp2.siz;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		string tmp; cin >> tmp;
		if (!v.size()) v.push_back({ tmp,1 });
		else {
			bool flag = false;
			for (int i = 0; i < v.size(); i++)
				if (v[i].input == tmp) {
					v[i].siz++;
					flag = true;
					break;
				}
			if (!flag) v.push_back({ tmp,1 });
		}
	}
	sort(v.begin(), v.end(), comp);
	cout << v[0].input << "\n";
}