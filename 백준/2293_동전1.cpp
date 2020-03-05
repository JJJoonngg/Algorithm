#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int *coin = new int[n+1];
	int *result = new int[k+1];

	for (int i = 1; i < n; i++) {
		cin >> coin[i];
	}
	result[k+1] = 0;
	for (int i = 1; i <= n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				result[j] += result[j - coin[i]];
			}
	}

	cout << result[k] << endl;

	delete[] coin;
	delete[] result;
	
	return 0;
}