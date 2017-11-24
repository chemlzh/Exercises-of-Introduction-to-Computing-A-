#include <cmath>
#include <cstdio>
long n, a, ans;
inline void dfs(long now, long minn) {
	ans++;
	for (long i = minn; i <= (long)sqrt(now + 0.5); i++) {
		if (now%i == 0) dfs(now / i, i);
	}
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		ans = 0, scanf("%ld", &a), dfs(a, 2), printf("%ld\n", ans);
	}
}