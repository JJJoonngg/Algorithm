/*
����
����̴� �ʵ��б��� �ٴ� ��, ���� ������ ���麸�� ���� �̸� �ϰ� ���� �Ⱓ�� ��Ҵ�. 
���� ������ ���а� ���� ���� Ǯ���̴�.
������ �� L���̴�. ������ �� B������, ����� �� A�������� Ǯ��� �Ѵ�. 
����̴� �Ϸ翡 ��� �ִ� C������, ������ �ִ� D������ Ǯ �� �ִ�.
����̰� �ܿ� ���е��� ������ ���� �ʰ� �� �� �ִ� �ִ� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� �ٿ� �ϳ��� �� �ټ� �ٿ� ���� L, A, B, C, D�� �־�����. 
(2 �� L �� 40, 1 �� A, B �� 1000, 1 �� C, D �� 100)
�׻� ���� ������ ���� �Ⱓ���� �� �� �� �ִ� ��츸 �Է����� �־�����.
20
25
30
6
8

���
ù° �ٿ� ����̰� �� �� �ִ� ���� �ִ밪�� ����Ѵ�
15
*/
#include <iostream>
using namespace std;
int main() {
	int day, Korpage, MathPage, Kor, Math;
	int remain, korday, mathday;
	cin >> day;
	cin >> Korpage;
	cin >> MathPage;
	cin >> Kor;
	cin >> Math;

	korday = (Korpage / Kor);
	if (Korpage % Kor != 0)	korday++;

	mathday = (MathPage / Math);
	if (MathPage % Math != 0) mathday++;

	remain = day - (korday > mathday ? korday : mathday);
	cout << remain << endl;
	return 0;
}