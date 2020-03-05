/*
문제
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

입력
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.
9999
출력
첫째줄에 필요한 세트의 개수를 출력한다.
2
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, arr[10] = { 0, }, num = 0;
	scanf("%d", &n);
	while (true) {
		arr[n % 10]++;
		if (!(n / 10)) break;
		n /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		num = max(num, arr[i]);
	}
	num = max(num, (arr[6] + arr[9] + 1) / 2);
	printf("%d\n", num);
	return 0;
}