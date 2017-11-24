#include <cstdio>
const long money[4] = { 0,5,2,1 },
				pow10[4] = { 1,10,100,1000 };
long n, cnt, f[4];
inline void dfs(long m, long s) {
	if (s == 3) {
		if (m%money[s] != 0) return;
		cnt++, f[s] = m / money[s];
		for (long i = 3; i >= 1; i--) printf("%ld", (cnt % pow10[i]) / pow10[i - 1]);
		for (long i = 3; i >= 1; i--) {
			long len = 0, tmp = f[i];
			if (!f[i]) len = 1;
			else { 
				while (tmp) len++, tmp /= 10; 
			}
			for (long j = 1; j <= 12 - len; j++) printf(" ");
			printf("%ld", f[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (long i = 0; i <= m / money[s]; i++) {
			f[s] = i, dfs(m - i*money[s], s + 1), f[s] = 0;
		}
	}
}
int main() {
	scanf("%ld", &n);
	dfs(n, 1);
}