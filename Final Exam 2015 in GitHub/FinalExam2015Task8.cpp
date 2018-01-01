#include <algorithm>
#include <cstdio>
using namespace std;
long n, maxn = -0x7fffffff, cnt, ans[55], dp[105][105][2];
char c, op[105];
inline long calc(long a, long b, char ch) {
	if (ch == 't') return a + b; else return a * b;
}
int main() {
	scanf("%ld%c", &n, &c);
	for (long i = 1; i < 2 * n; i++) {
		for (long j = 1; j < 2 * n; j++) dp[i][j][0] = -0x7fffffff, dp[i][j][1] = 0x7fffffff;
	}
	for (long i = 1; i <= n; i++) {
		scanf("%c %ld%c", &op[i - 1], &dp[i][i][0], &c);
		op[i + n - 1] = op[i - 1];
		dp[n + i][n + i][1] = dp[i][i][1] = dp[n + i][n + i][0] = dp[i][i][0];
	}
	op[2 * n] = op[n];
	for (long k = 1; k <= n; k++) {
		for (long i = 1; i <= 2 * n - 1; i++) {
			long tmp = i + k - 1;
			if (tmp >= 2 * n) break;
			for (long j = i; j < tmp; j++) {
				dp[i][tmp][0] = max(dp[i][tmp][0], calc(dp[i][j][0], dp[j + 1][tmp][0], op[j]));
				dp[i][tmp][0] = max(dp[i][tmp][0], calc(dp[i][j][1], dp[j + 1][tmp][1], op[j]));
				dp[i][tmp][1] = min(dp[i][tmp][1], calc(dp[i][j][1], dp[j + 1][tmp][1], op[j]));
				dp[i][tmp][1] = min(dp[i][tmp][1], calc(dp[i][j][0], dp[j + 1][tmp][1], op[j]));
				dp[i][tmp][1] = min(dp[i][tmp][1], calc(dp[i][j][1], dp[j + 1][tmp][0], op[j]));
			}
		}
	}
	for (long i = 1; i <= n; i++) {
		if (maxn < dp[i][i + n - 1][0]) maxn = dp[i][i + n - 1][0], cnt = 1, ans[cnt] = i;
		else if (maxn == dp[i][i + n - 1][0]) ans[++cnt] = i;
	}
	printf("%ld\n", maxn);
	for (long i = 1; i <= cnt; i++) {
		printf("%ld", ans[i]);
		if (i != cnt) printf(" ");
	}
}