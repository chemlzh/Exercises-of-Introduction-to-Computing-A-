#include <cstdio>
long n, m, k, tmp, res, ans[36][1000];
int main() {
	scanf("%ld,%ld,%ld", &m, &n, &k);
	for (long i = m + 1; i <= n - 1; i++) {
		tmp = i, res = 0;
		while (tmp) res += tmp % 10, tmp /= 10;
		ans[res][++ans[res][0]] = i;
	}
	for (long i = k; i <= 36; i += k) {
		if (ans[i][0]) {
			for (long j = 1; j < ans[i][0]; j++) printf("%ld,", ans[i][j]);
			printf("%ld\n", ans[i][ans[i][0]]);
		}
	}
}