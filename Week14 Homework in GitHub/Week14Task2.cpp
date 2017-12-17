#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long t, m, n;
long a[75], b[75];
int main() {
	scanf("%ld", &t);
	for (long i = 1; i <= t; i++) {
		scanf("%ld%ld", &m, &n);
		memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
		for (long j = 0; j < m; j++) scanf("%ld", &a[j]);
		for (long j = 0; j < n; j++) scanf("%ld", &b[j]);
		for (long j = 0; j <= m + n - 2; j++) {
			long tmp = 0;
			for (long k = 0; k <= j; k++) {
				tmp += a[k] * b[j - k];
			}
			printf("%ld", tmp);
			if (j != m + n - 2) printf(" "); else printf("\n");
		}
	}
}