/*
�Է�
������ ù ��° ���� ����� ���� n(1 �� n �� 10,000)�̴�. ��° �ٺ��� n��° �ٱ��� �� ������ ���� ������ ���´�. 
������ ���� ������ �� ���� ������ �̷���� �ִ�. ù ��° ������ ������ �����ϴ� �� ��� �� �θ� ����� ��ȣ�� ��Ÿ����,
�� ��° ������ �ڽ� ��带, �� ��° ������ ������ ����ġ�� ��Ÿ����. ������ ���� ������ �θ� ����� ��ȣ�� ���� ���� ���� �Էµǰ�,
�θ� ����� ��ȣ�� ������ �ڽ� ����� ��ȣ�� ���� ���� ���� �Էµȴ�. 
��Ʈ ����� ��ȣ�� �׻� 1�̶�� �����ϸ�, ������ ����ġ�� 100���� ũ�� ���� ���� �����̴�.
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
���
ù° �ٿ� Ʈ���� ������ ����Ѵ�.
45
*/
#include <iostream>
#include <vector>
#include <string.h>
#define MAXI 10000+1
using namespace std;
struct info { int node; int value; };
vector<info> tree[MAXI];
bool check[MAXI];
int res = 0, newRoot = 0;
void search(int node, int val){
	check[node] = true;
	for (auto a : tree[node]) {
		if (!check[a.node]) {
			int tmp = a.value + val;
			search(a.node, tmp);
			if (tmp > res) {
				res = tmp;
				newRoot = a.node;
			}
		}
	}
	/*for (int i = 0; i < tree[node].size(); i++) {
		int tmpN = tree[node][i].node;
		int tmpV = tree[node][i].value;
		if (!check[tmpN]) {
			search(tmpN, tmpV + val);
			if (tmpV + val > res) {
				res = tmpV + val;
				newRoot = tmpN;
			}
		}
	}*/
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while(n--) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	search(1, 0);
	memset(check, false, sizeof(check));
	search(newRoot, 0);
	cout << res << "\n";
}