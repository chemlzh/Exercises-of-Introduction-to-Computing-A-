#include <cstdio>
#include <cstring>
long k, m, flag[30];
int main() {
	for (;;) {
		scanf("%ld", &k);
		if (k == 0) return 0;
		for (long a = 0;; a++) {
			long tmp, f, r;
			for (long b = k + 1; b <= 2 * k; b++) {
				memset(flag, 0, sizeof(flag));
				tmp = 0, f = 1, r = 2 * a*k + b;
				for (long i = 1; i <= k; i++) {
					for (long j = 1; j <= r; j++) {
						do { tmp = tmp % (2 * k) + 1; } while (flag[tmp]);
					}
					if (tmp <= k) { f = 0; break; }
					else flag[tmp] = 1;
				}
				if (f) { printf("%ld\n", r); break; }
			}
			if (f) break;
		}
	}
}