#include <cstdio>
#include <cstring>
const long pn[10] = { 1,1,4,27,256,3125,46656,823543,16777216,387420489 };
long n, ans, tmp, now, cnt;
long a[10][10], s[10], delta[10], f[10];
int main() {
	for (;;) {
		scanf("%ld", &n), ans = 0, memset(s, 0, sizeof(s));
		if (n == -1) break;
		for (long i = 0; i <= n - 1; i++) {
			for (long j = 0; j <= n - 1; j++) scanf("%ld", &a[i][j]), s[j] += a[i][j];
		}
		for (long i = 0; i <= n - 1; i++) {
			if (ans < s[i]) ans = s[i];
		}
		for (long i = 1; i <= pn[n] / n - 1; i++) {
			tmp = i, now = 0, cnt = 0;
			memset(delta, 0, sizeof(delta));
			while (tmp) {
				for (long j = 0; j <= n - 1; j++) delta[j] += a[cnt][(j + tmp%n) % n] - a[cnt][j];
				cnt++, tmp /= n;
			}
			for (long j = 0; j <= n - 1; j++) {
				if (now < s[j] + delta[j]) now = s[j] + delta[j];
			}
			if (ans > now) ans = now;
		}
		printf("%ld\n", ans);
	}
}