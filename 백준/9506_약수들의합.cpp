#include <iostream>
using namespace std;

//Perfect Number Judge & print result
int main() {
	int n = 0;
	while (true) {
		cin >> n;
		int sum = 0;
		if (n == -1) break;
		for(int i = 1;i < n; i++) {
			if (n % i == 0) {
				sum += i;
			}
		}
		if (sum == n) {
			cout << n << " = ";
			for (int i = 1; i < n; i++) {
				if (i == 1)
					cout << "1";
				if ((i >1) &&(n % i == 0)) {
					cout <<" + "<<i;
				}
			}
			cout << endl;
		}
		else {
			cout << n << " is NOT perfect." << endl;
		}
	}
	return 0;
	
}