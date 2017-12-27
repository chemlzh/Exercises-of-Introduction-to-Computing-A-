#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long n, k, p, cnt, a[25], f[2005];

inline void work() {
	memset(f, 0, sizeof(f)), f[0] = 1, p = 0;
	while (f[p]) {
		if (f[p] <= k) {
			for (long i = 1; i <= n; i++) {
				if (!f[p + a[i]]) f[p + a[i]] = f[p] + 1;
				else f[p + a[i]] = min(f[p + a[i]], f[p] + 1);
			}
		}
		p++;
	}
	printf("%ld\n", p - 1);
}

int main() {
	scanf("%ld,%ld", &n, &k);
	for (;;) {
		long flag = 1;
		for (long i = 1; i <= n; i++) {
			scanf("%ld", &a[i]);
			if (!a[i]) { flag = 0; break; }
		}
		if (!flag) break;
		else work();
	}
}