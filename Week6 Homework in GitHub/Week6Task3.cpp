#include <cstdio>
long n, a[20][20];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n - 1; i++) {
		if (i % 2) {
			for (long j = 1; j <= i; j++) {
				a[i - j + 1][j] = i*(i - 1) / 2 + j;
				a[n - i + j][n - j + 1] = n*n + 1 - i*(i - 1) / 2 - j;
			}
		}
		else {
			for (long j = 1; j <= i; j++) {
				a[j][i - j + 1] = i*(i - 1) / 2 + j;
				a[n - j + 1][n - i + j] = n*n + 1 - i*(i - 1) / 2 - j;
			}
		}
	}
	for (long i = 1; i <= n; i++) {
		if (n % 2==0) a[i][n - i + 1] = n*(n - 1) / 2 + i;
		else a[n - i + 1][i] = n*(n - 1) / 2 + i;
	}
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) {
			printf("%ld", a[i][j]);
			if (j != n) printf(" ");
		}
		printf("\n");
	}
}