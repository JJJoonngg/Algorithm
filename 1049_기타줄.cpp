
/*
문제
김지민은 세계적인 기타 플레이어이다. 불행하게도 N개의 줄이 끊어졌다. 
따라서 새로운 줄을 사거나 교체해야 한다. 세계적인 기타리스트인 김지민은 되도록이면 돈을 적게쓰려고 한다.
김지민은 6줄 패키지를 살 수도 있지만, 1개 또는 그 이상의 줄을 낱개로 살 수도 있다.
끊어진 기타 줄의 개수 N과 기타줄 브랜드 M개가 주어지고, 
각각의 브랜드에서 파는 기타줄 6개가 들어있는 패키지의 가격, 낱개로 살 때의 가격이 주어질 때,
적어도 N개를 사기 위해 필요한 돈의 수를 최소로 하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 M이 주어진다. N은 100보다 작거나 같은 자연수이고, M은 50보다 작거나 같은 자연수이다.
둘째 줄부터 M개의 줄에는 각 브랜드의 패키지 가격과 낱개의 가격이 공백으로 구분하여 주어진다. 
가격은 0보다 크거나 같고, 1,000보다 작거나 같은 자연수이다.

N M
4 2
Package Piece
12		3
15		4

출력
첫째 줄에 김지민이 기타줄을 적어도 N개 사기 위해 필요한 돈의 최솟값을 출력한다
12
*/
#include <iostream>
using namespace std;
#define MaxBrand 51

int main() {
	int N, M;
	int quotient, mod;
	int Package[MaxBrand];
	int Piece[MaxBrand];
	int MinPackage, MinPiece, MinPrice;

	cin >> N >> M;
	quotient = N / 6;
	mod = N % 6;

	MinPackage = 1000;
	MinPiece = 1000;

	for (int i = 0; i < M; i++) {
		cin >> Package[i] >> Piece[i];

		if (MinPackage > Package[i])
			MinPackage = Package[i];

		if (MinPiece > Piece[i])
			MinPiece = Piece[i];
	}

	MinPrice = MinPackage * quotient;

	if (mod*MinPiece > MinPackage)	MinPrice += MinPackage;
	else MinPrice += mod * MinPiece;

	cout << MinPrice << endl;


	return 0;
}