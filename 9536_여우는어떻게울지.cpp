/*
����
��� �̽��׸��� �������� ������ �����Ҹ��� �������� ���� �ѽ��̴� ���� ������� �����ϰ� ������ ����. 
������ ������ �������� ������, ������ �������� �ٸ� �������� �����Ҹ��� ���� �ִ�. 
�׷��� �ѽ��̴� ö���� �غ� �� �Ա� ������ �ٸ� �������� � �����Ҹ��� ������ ��Ȯ�� �˰� �ִ�.
�׷��Ƿ� �� �Ҹ��� ��� �ɷ����� ���� ������ �и��� ������ �����Ҹ��� ���̴�.

�Է�
ù ��° �ٿ��� �׽�Ʈ���̽��� ���� T�� �Էµȴ�. �� �׽�Ʈ���̽��� �Ʒ��� ���� �����Ǿ� �ִ�.
�׽�Ʈ���̽��� ù �ٿ��� �� ���� �ܾ�� �̷���� ������ �Ҹ��� �Էµȴ�. �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� ������ �������� ���еȴ�. 
�ܾ��� ���̴� �ִ� 100�����̰�, �ܾ��� ������ �ִ� 100���̴�. ���� �ٺ��ʹ� ���츦 ������ �������� �����Ҹ��� <����> goes <�Ҹ�>�� ���·� �Էµȴ�. 
�ּ� 1����, �ִ� 100�����̸�, �̸��� �ִ� 100�����̰� ������ �����ϴ� ������ �̸��̴�. ���츦 ������ ������ �����Ҹ��� �� �ܾ��̰� �ִ� 100�����̴�.
������ �ٿ��� �ѽ��̰� �˰� �;��ϴ� ������ �־�����. what does the fox say?
1
toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
dog goes woof
fish goes blub
elephant goes toot
seal goes ow
what does the fox say?

2
pow
dog goes woof
what does the fox say?
woof
dog goes pow
what does the fox say?

���
�� �׽�Ʈ���̽����� ������ �����Ҹ��� �� �پ�, ������ ������� ����Ѵ�. ������ �����Ҹ��� �����Ǿ� ������ ����ȴ�. 
(�˷��� �Ͱ��� �޸�, ����� �� ��ȣ�� �ǻ�������� �ʴ´�.)
wa pa pa pa pa pa pow

pow
woof
*/

#include <iostream>
#include <string.h>
#define MAX 111
int main() {
	int t;  scanf("%d", &t);
	while (t--) {
		char input[MAX*MAX], animal[MAX][MAX], name[MAX], goes[MAX], bark[MAX];
		while (getchar() != '\n');
		scanf("%[^\n]s", input);
		int cnt = 0;
		while (true) {
			scanf("%s %s %s", name, goes, bark);
			if (!strcmp(name, "what") && !strcmp(goes, "does") && !strcmp(bark, "the")) break;
			strcpy(animal[cnt++], bark);
		}
		char *cut = strtok(input, " ");
		while (cut != NULL) {
			bool judge = true;
			for (int i = 0; i < cnt; i++)
				if (!strcmp(cut, animal[i])) {
					judge = false;
					break;
				}
			if (judge) printf("%s ", cut);
			cut = strtok(NULL, " ");
		}
		printf("\n");
	}
	return 0;
}