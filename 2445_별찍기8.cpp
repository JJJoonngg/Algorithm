#include <iostream>
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)printf("*");
		for (int j = n; j > i; j--)printf(" ");
		for (int j = n; j > i; j--)printf(" ");
		for (int j = 1; j <= i; j++)printf("*");
		printf("\n");
	}
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--)printf("*");
		for (int j = 1; j <= i; j++)printf(" ");
		for (int j = 1; j <= i; j++)printf(" ");
		for (int j = n - 1; j >= i; j--)printf("*");
		printf("\n");
	}
	return 0;
}