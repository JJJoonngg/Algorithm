#include <iostream>
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--)printf("*");
		printf("\n");
	}
	return 0;
}