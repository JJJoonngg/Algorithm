#include <iostream>
using namespace std;

int main() {
	int T, n;

	int base[] = {0,1,2,4};
	int arr[12];
	cin >> T;
	for (int i = 0; i < 12; i++) {
		if (i < 4) arr[i] = base[i];
		else arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << arr[n] << endl;
	}

	return 0;
}