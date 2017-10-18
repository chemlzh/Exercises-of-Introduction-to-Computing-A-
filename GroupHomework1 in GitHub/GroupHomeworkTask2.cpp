#include <cstdio>
long n, ans, tmp, res;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &tmp);
		res = tmp % 10;
		while (tmp) { tmp /= 10; res -= tmp % 10; }
		if (res > 0) ans++;
	}
	printf("%ld", ans);
}