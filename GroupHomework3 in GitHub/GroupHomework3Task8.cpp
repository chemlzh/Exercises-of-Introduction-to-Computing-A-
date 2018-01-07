#include <cstdio>
#include <cstring>
long n, c1, c2, sum, weight, maxw = -1, cnt, ans[64], tmp[64], a[64];
inline void dfs(long item, long use) {
	if (item > n) {
		if (weight > maxw) memcpy(ans, tmp, sizeof(tmp)), cnt = use, maxw = weight;
		return;
	}
	else {
		if (weight + a[item] <= c1) {
			tmp[item] = 1, weight += a[item], dfs(item + 1, use + 1), tmp[item] = 0, weight -= a[item];
		}
		dfs(item + 1, use);
	}
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld", &a[i]), sum += a[i];
	scanf("%ld%ld", &c1, &c2), dfs(1, 0);
	if (maxw == -1 || sum - maxw > c2) printf("%s", "can't find a way to Loading");
	else {
		printf("%s\n%s\n", "ok,can load it", "a way is:");
		printf("%s", "the first trip load:");
		long c = 0;
		for (long i = 1; i <= n; i++) {
			if (ans[i]) {
				printf("%ld", a[i]), c++;
				if (c < cnt) printf(" "); else { printf("\n"); break; }
			}
		}
		printf("%s", "the second trip load:");
		c = 0;
		for (long i = 1; i <= n; i++) {
			if (!ans[i]) {
				printf("%ld", a[i]), c++;
				if (c < n - cnt) printf(" "); else { printf("\n"); break; }
			}
		}
	}
}