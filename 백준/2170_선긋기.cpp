/*
https://www.acmicpc.net/problem/2170
����
�ſ� ū ��ȭ���� �ڸ� ��� ���� �������� �Ѵ�. ���� ���� ������ ���� �� ������ �ٸ� �� ������ �߰� �ȴ�. 
���� ���� ������ �̹� ���� �ִ� ��ġ�� ���ļ� �׸� ���� �ִµ�, ���� �� ���� ���� �� �� ���� ���� ���̸� ������ �� ���ٰ� ����.

�̿� ���� ������ ���� �׾��� ��, �׷��� ��(��)�� �� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
���� ���� �� �׷��� ���� �� ������ ����Ѵ�.

�Է�
ù° �ٿ� ���� ���� Ƚ�� N(1��N��1,000,000)�� �־�����. ���� N���� �ٿ��� ���� ���� �� ������ �� ���� �־�����. 
������ ������ -1,000,000,000 �̻� 1,000,000,000 ������ �����̴�.
4
1 3
2 5
3 5
6 7
���
ù° �ٿ� ���� ���� �� ���̸� ����Ѵ�.
5
*/
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
struct info { int start, end; };
bool comp(info tmp1, info tmp2) { 
	if(tmp1.start != tmp2.start) return tmp1.start < tmp2.start; 
	else return tmp1.end < tmp2.end;
}
vector<info> v;
int s, e, res = 0;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(), comp);
	s = e = -INF;
	for (int i = 0; i < v.size(); i++) {
		if (e < v[i].start) {
			res += e - s;
			s = v[i].start;
			e = v[i].end;
		}
		else e = max(e, v[i].end);
	}
	res += e - s;
	cout << res << "\n";
}