#include <cstdio>
long n, m[105][105],a[10005];
long x1, y1, t1;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) scanf("%ld", &m[i][j]);
	}
	x1 = 1; y1 = 1; t1 = 1;
	for (long i = 1; i <= n*n; i++) {
		if (i<=(n*n+1)/2) a[2*i-1] = m[x1][y1];
		else a[(n*n - i + 1) * 2] = m[x1][y1];
		if (x1 == t1 + 1 && y1 == t1) t1++;
		if (x1 == t1 && y1 < n - t1+1) y1++;
		else if (x1 < n - t1+1&&y1 == n - t1+1) x1++;
		else if (x1 == n - t1 + 1 && y1 > t1) y1--;
		else if (x1 > t1 && y1 == t1) x1--;
	}
	for (long i = 1; i <= n*n; i++) {
		printf("%ld", a[i]);
		if (i != n*n) printf(" ");
	}
}