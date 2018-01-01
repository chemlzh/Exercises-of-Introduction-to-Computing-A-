#include <algorithm>
#include <cstdio>
using namespace std;
long n, ans, a[105][105], f[105][105];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= i; j++) scanf("%ld", &a[i][j]);
	}
	f[1][1] = a[1][1];
	for (long i = 2; i <= n; i++) {
		f[i][1] = f[i - 1][1] + a[i][1], f[i][i] = f[i - 1][i - 1] + a[i][i];
		for (long j = 2; j <= i - 1; j++) f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
	}
	for (long i = 1; i <= n; i++) ans = max(ans, f[n][i]);
	printf("%ld", ans);
}