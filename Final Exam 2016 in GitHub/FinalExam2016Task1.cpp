#include <cstdio>
long m, n, pic[105][105];
int main() {
	scanf("%ld%ld", &m, &n);
	for (long i = 1; i <= m; i++) {
		for (long j = 1; j <= n; j++) scanf("%ld", &pic[i][j]);
	}
	for (long i = 1; i <= n; i++) {
		for (long j = m; j > 1; j--) printf("%ld ", pic[j][i]);
		printf("%ld\n", pic[1][i]);
	}
}