#include <cstdio>
long n,m,maxnum=2,a[25];
int main() {
	scanf("%ld", &n); a[1] = 1; a[2] = 1;
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &m);
		if (m <= maxnum) printf("%ld", a[m]);
		else {
			for (long i = maxnum + 1; i <= m; i++) a[i] = a[i - 1] + a[i - 2];
			printf("%ld", a[m]);
		}
		if (i != n) printf("\n");
	}
}