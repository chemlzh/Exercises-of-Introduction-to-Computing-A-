#include <cstdio>
#include <cstring>
long k, m, flag[30];
int main() {
	for (;;) {
		scanf("%ld", &k);
		if (k == 0) return 0;
		for (long m = k + 1; ; m++) {
			memset(flag, 0, sizeof(flag));
			long tmp = 0, f = 1;
			for (long i = 1; i <= k; i++) {
				for (long j = 1; j <= m; j++) {
					do { tmp = tmp % (2 * k) + 1; } while (flag[tmp]);
				}
				if (tmp <= k) { f = 0; break; }
				else flag[tmp] = 1;
			}
			if (f) { printf("%ld\n", m); break; }
		}
	}
}