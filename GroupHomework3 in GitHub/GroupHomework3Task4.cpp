#include <cstdio>
long g, n, m, k;
long *a, *b;

inline void init(long **num, long r,long c) {
	*num = new long[r*c];
	for (long i = 0; i < r; i++) {
		for (long j = 0; j < c; j++) scanf("%ld", *num + i * c + j);
	}
}

inline void solve(long *n1, long *n2, long n, long m, long k) {
	long *t1, *t2, res;
	for (long i = 0; i < n; i++) {
		for (long j = 0; j < k; j++) {
			t1 = n1 + i * m, t2 = n2 + j, res = 0;
			for (long l = 0; l < m; l++) {
				res += *t1 * *t2, t1 += 1, t2 += k;
			}
			printf("%ld", res);
			if (j != k - 1) printf(" "); else printf("\n");
		}
	}
}

int main() {
	scanf("%ld", &g);
	for (long i = 1; i <= g; i++) {
		scanf("%ld%ld%ld", &n, &m, &k);
		init(&a, n, m), init(&b, m, k);
		solve(a, b, n, m, k);
		delete a, a = NULL, delete b, b = NULL;
	}
}