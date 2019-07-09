/*
문제
상근이와 친구들은 MT에 가서 아래 설명과 같이 재미있는 게임을 할 것이다.
각 플레이어는 1이상 100 이하의 정수를 카드에 적어 제출한다.
각 플레이어는 자신과 같은 수를 쓴 사람이 없다면, 자신이 쓴 수와 같은 점수를 얻는다.
만약, 같은 수를 쓴 다른 사람이 있는 경우에는 점수를 얻을 수 없다.
상근이와 친구들은 이 게임을 3번 했다.
각 플레이어가 각각 쓴 수가 주어졌을 때, 3번 게임에서 얻은 총 점수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 참가자의 수 N이 주어진다. (2 ≤ N ≤ 200)
둘째 줄부터 N개 줄에는 각 플레이어가 1번째, 2번째, 3번째 게임에서 쓴 수가 공백으로 구분되어 주어진다.
5
100 99 98
100 97 92
63 89 63
99 99 99
89 97 98

출력
각 플레이어가 3번의 게임에서 얻은 총 점수를 입력으로 주어진 순서대로 출력한다.
0
92
215
198
89

힌트
플레이어 1 : 0 + 0 + 0 = 0
플레이어 2 : 0 + 0 + 92 = 92
플레이어 3 : 63 + 89 + 63 = 215
플레이어 4 : 99 + 0 + 99 = 198
플레이어 5 : 89 + 0 + 0 = 89
*/
#include <iostream>
using namespace std;
#define MAX 201
int main() {
	int n, tmp,count;
	int score[MAX][3];
	int SumOfScore[MAX];
	
	//insert info
	cin >> n;
	count = n - 1;
	for (int i = 0; i < n; i++) {
		SumOfScore[i] = 0;
		for (int j = 0; j < 3; j++)
			cin >> score[i][j];
	}
	//calculate score
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 3; k++) {
			tmp = 0;
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				if (score[i][k] != score[j][k])
					tmp++;
			}
			if (tmp == count) 	SumOfScore[i] += score[i][k];
		}
	}

	//print final score
	for (int i = 0; i < n; i++) {
		cout << SumOfScore[i] << endl;
	}
	return 0;
}