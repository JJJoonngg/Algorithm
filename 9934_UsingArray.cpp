#include <iostream>
#include <math.h>

using namespace std;
int arr[1025];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int k;
	cin >> k;
	int size = pow(2, k);
	for (int i = 1; i < size; i++) cin >> arr[i];

	int start_idx = size / 2;
	int d = size;
	int cnt = 1;

	for (int i = 0; i < k; i++) {
		int idx = start_idx;
		for (int j = 0; j < cnt; j++) {
			cout << arr[idx] << " ";
			idx += d;
		}
		start_idx /= 2;
		d /= 2;
		cnt *= 2;
		
		cout << endl;
	}
}