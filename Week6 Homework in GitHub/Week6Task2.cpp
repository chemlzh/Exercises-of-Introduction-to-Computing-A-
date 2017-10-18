#include <cstdio>
const long Max = 105;
long n,a[Max][Max],b[Max][Max];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) scanf("%ld", &a[i][j]);
	}
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) scanf("%ld", &b[i][j]);
	}
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) {
			printf("%ld", a[i][j] + b[i][j]);
			if (j < n) printf(" ");
		}
		printf("\n");
	}
}