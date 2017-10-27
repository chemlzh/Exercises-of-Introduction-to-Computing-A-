#include <cmath>
#include <cstdio>
long n,m;
long long f[305005];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= (long)sqrt(i); j++) {
			if (i%j==0) {
				if (i == j*j) f[i] += j; else f[i] += j + i / j;
			}
		}
		f[i] -= i;
	}
	for (long i = 1; i <= n; i++) {
		if (i == f[f[i]] && i < f[i]) printf("%ld %lld\n", i, f[i]);
	}
}