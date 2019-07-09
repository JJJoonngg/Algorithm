
/*
����
�������� �������� ��Ÿ �÷��̾��̴�. �����ϰԵ� N���� ���� ��������. 
���� ���ο� ���� ��ų� ��ü�ؾ� �Ѵ�. �������� ��Ÿ����Ʈ�� �������� �ǵ����̸� ���� ���Ծ����� �Ѵ�.
�������� 6�� ��Ű���� �� ���� ������, 1�� �Ǵ� �� �̻��� ���� ������ �� ���� �ִ�.
������ ��Ÿ ���� ���� N�� ��Ÿ�� �귣�� M���� �־�����, 
������ �귣�忡�� �Ĵ� ��Ÿ�� 6���� ����ִ� ��Ű���� ����, ������ �� ���� ������ �־��� ��,
��� N���� ��� ���� �ʿ��� ���� ���� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� M�� �־�����. N�� 100���� �۰ų� ���� �ڿ����̰�, M�� 50���� �۰ų� ���� �ڿ����̴�.
��° �ٺ��� M���� �ٿ��� �� �귣���� ��Ű�� ���ݰ� ������ ������ �������� �����Ͽ� �־�����. 
������ 0���� ũ�ų� ����, 1,000���� �۰ų� ���� �ڿ����̴�.

N M
4 2
Package Piece
12		3
15		4

���
ù° �ٿ� �������� ��Ÿ���� ��� N�� ��� ���� �ʿ��� ���� �ּڰ��� ����Ѵ�
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