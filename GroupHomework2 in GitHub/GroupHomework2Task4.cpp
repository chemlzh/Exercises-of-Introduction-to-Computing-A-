#include <cstdio>
#include <cstring>
const long d[9][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{0,0} };
long m, n, a[15][15],b[15][15];
int main() {
	scanf("%ld%ld", &m, &n);
	a[5][5] = m;
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= 9; j++) {
			for (long k = 1; k <= 9; k++) {
				for (long l = 0; l <= 8; l++)
					if (j + d[l][0] >= 1 && j + d[l][0] <= 9 && k + d[l][1] >= 1 && k + d[l][1] <= 9) b[j + d[l][0]][k + d[l][1]] += a[j][k];
			}
		}
		for (long j = 1; j <= 9; j++) {
			for (long k = 1; k <= 9; k++) a[j][k] += b[j][k];
		}
		memset(b, 0, sizeof(b));
	}
	for (long i = 1; i <= 9; i++) {
		for (long j = 1; j < 9; j++) printf("%ld ", a[i][j]);
		printf("%ld\n", a[i][9]);
	}
}