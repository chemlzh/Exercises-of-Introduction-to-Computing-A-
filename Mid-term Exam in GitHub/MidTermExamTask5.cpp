#include <cstdio>
long row, col, a[105][105];
int main() {
	scanf("%ld%ld", &row, &col);
	for (long i = 1; i <= row; i++) {
		for (long j = 1; j <= col; j++) scanf("%ld", &a[i][j]);
	}
	for (long i = 1; i <= col; i++) {
		long x = 1, y = i;
		while (x <= row && y >= 1) printf("%ld\n", a[x][y]), x++, y--;
	}
	for (long i = 2; i <= row; i++) {
		long x = i, y = col;
		while (x <= row && y >= 1) printf("%ld\n", a[x][y]), x++, y--;
	}
}