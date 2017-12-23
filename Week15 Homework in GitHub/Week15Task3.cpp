#include <cstdio>
long n, k, ans;
int main() {
	scanf("%ld%ld", &n, &k);
	if (n <= k) ans = 2;
	else if ((2 * n) % k != 0) ans = 2 * n / k + 1;
	else ans = 2 * n / k;
	printf("%ld", ans);
}