/*
order (���̺� ��ȣ n) (�ֹ��ð� t): �ֹ� �ð� t�� ���̺� n���� �ֹ� ���� (�ֹ��� ������ ���� �ִ� ����Ʈ�յ��� �� �ڿ� �� ����Ʈ���� �߰�)
sort: �ֹ� �ð��� ���� ������� ����
complete n: n�� ���̺��� �丮 �ϼ�. (�丮�� �ϼ��ϴ� ������ �ش� ���̺� �� �� �̻��� �ֹ��� �з� �ְų� �ֹ��� ���� ���� �������� ����

�Է�
�Է��� ù° �ٿ� ������ �� N�� ���̺��� �� M�� �־�����. (1��N, M��100)
���� N�ٿ� ������ ��ɾ���� �־�����.
����Ʈ���� ������ �� �ֹ� �ð��� ���ٸ� ���̺� ��ȣ�� ���� ���� �� �տ� ���´�. (1 �� �ֹ� �ð� �� 1,000 , 1 �� ���̺� ��ȣ �� M)
7 3
order 1 4
order 2 2
order 3 3
sort
complete 3
complete 2
complete 1
���
�� �ٿ� �� ��ɾ ����� ���� ����Ʈ�յ鿡 ���� ���̺� ��ȣ�� ����Ѵ�. �ƹ� ����Ʈ�յ� ���� ��� sleep�� ����Ѵ�.
1
1 2
1 2 3
2 3 1
2 1
1
sleep
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct info { int num; int time; };
bool comp(info tmp1, info tmp2) {
	if (tmp1.time == tmp2.time) return tmp1.num < tmp2.num;
	else return tmp1.time < tmp2.time;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<info> v;
	while (n--) {
		string input; 
		int number, t;
		cin >> input;
		if (input == "order") {
			cin >> number >> t;
			v.push_back({ number,t });
		}
		else if (input == "sort") sort(v.begin(), v.end(), comp);
		else if (input == "complete") {
			cin >> number;
			vector<info>::iterator it;
			for (it = v.begin(); it != v.end(); it++) {
				if (it->num == number) break;
			}
			v.erase(it);
		}
		if (v.size() == 0) cout << "sleep\n";
		else {
			vector<info>::iterator it;
			for (it = v.begin(); it != v.end(); it++) {
				cout << it->num << " ";
			}
			cout << "\n";
		}
	}

}