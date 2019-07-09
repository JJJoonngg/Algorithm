#include <iostream>
int main() {
	int n; scanf("%d", &n);
	/*12
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) printf(" ");
		for (int k = 1; k <= i; k++)printf("*");
		printf("\n");
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= i; j++) printf(" ");
		for (int k = 1; k <= n - i; k++)printf("*");
		printf("\n");
	}*/
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++)printf("*");
		printf("\n");
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int k = 1; k <= n - i; k++)printf("*");
		printf("\n");
	}

}