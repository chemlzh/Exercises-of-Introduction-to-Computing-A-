#include <cstdio>
long n, sum, tmp, maxn, cnt;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &tmp), sum += tmp;
		if (maxn < tmp) maxn = tmp, cnt = 1;
		else if (maxn == tmp) cnt++;
	}
	printf("%ld", sum - maxn * cnt);
}