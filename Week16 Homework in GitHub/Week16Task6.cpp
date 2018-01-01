#include <cstdio>
#include <algorithm>
using namespace std;
long n, t, p, ans, dp[200005];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &t);
		p = upper_bound(dp, dp + ans, t) - dp;
		if (p == ans) ans++;
		dp[p] = t;
	}
	printf("%ld", ans);
}