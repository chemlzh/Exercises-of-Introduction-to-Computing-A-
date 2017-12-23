#include <algorithm>
#include <cstdio>
using namespace std;
long t, m, v[105], c[105], f[1005];
int main() {
	scanf("%ld%ld", &t, &m);
	for (long i = 1; i <= m; i++) scanf("%ld%ld", &c[i], &v[i]);
	for (long i = 1; i <= m; i++) {
		for (long j = t; j >= c[i]; j--) f[j] = max(f[j],f[j-c[i]]+v[i]);
	}
	printf("%ld", f[t]);
}