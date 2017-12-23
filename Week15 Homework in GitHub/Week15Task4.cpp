#include <algorithm>
#include <cstdio>
using namespace std;
long m, n, ans;
long map[105][105], h[105][105], l[105][105], r[105][105];
int main() {
	scanf("%ld%ld", &m, &n);
	for (long i = 1; i <= m; i++) {
		for (long j = 1; j <= n; j++) scanf("%ld", &map[i][j]);
	}
	for (long i = 1; i <= n; i++) r[0][i] = n;
	for (long i = 1; i <= m; i++) {
		long maxl = 1, maxr = n;
		for (long j = 1; j <= n; j++) {
			if (map[i][j]) h[i][j] = l[i][j] = 0, maxl = j + 1;
			else {
				h[i][j] = h[i - 1][j] + 1, l[i][j] = max(maxl, l[i - 1][j]);
			}
		}
		for (long j = n; j >= 1; j--) {
			if (map[i][j]) r[i][j] = n, maxr = j - 1;
			else {
				r[i][j] = min(maxr, r[i - 1][j]);
				ans = max(ans, h[i][j] * (r[i][j] - l[i][j] + 1));
			}
		}
	}
	printf("%ld", ans);
}