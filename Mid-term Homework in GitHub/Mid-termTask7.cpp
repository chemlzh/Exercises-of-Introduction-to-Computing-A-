#include <algorithm>
#include <cstdio>
using namespace std;
long m, n, r, s, a[105][105], b[105][105];
long now, ans = 2147483647, x, y;
int main() {
	scanf("%ld%ld", &m, &n);
	for (long i = 1; i <= m; i++)
		for (long j = 1; j <= n; j++) scanf("%ld", &a[i][j]);
	scanf("%ld%ld", &r, &s);
	for (long i = 1; i <= r; i++)
		for (long j = 1; j <= s; j++) scanf("%ld", &b[i][j]);
	for (long i = 1; i <= m - r + 1; i++) {
		for (long j = 1; j <= n - s + 1; j++) {
			now = 0;
			for (long k = 1; k <= r; k++) {
				for (long l = 1; l <= s; l++) { now += abs(b[k][l] - a[k + i - 1][l + j - 1]); }
			}
			if (ans > now) { ans = now; x = i; y = j; }
		}
	}
	for (long i = x; i <= x + r - 1; i++) {
		for (long j = y; j <= y + s - 1; j++) {
			printf("%ld ", a[i][j]);
		}
		printf("\n");
	}	
}