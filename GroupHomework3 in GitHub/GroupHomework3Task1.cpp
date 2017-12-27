#include <algorithm>
#include <cstdio>
using namespace std;
struct blog { long cnt, p, people[105]; }b[105], ans;
long n, t, k, m, tmp, pos;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &t, &k);
		for (long j = 1; j <= k; j++) {
			scanf("%ld", &tmp), m = max(m, tmp), b[tmp].cnt++;
			if (!b[tmp].people[t])  b[tmp].people[t] = 1, b[tmp].p++;
		}
	}
	for (long i = 1; i <= m; i++) {
		if (ans.cnt < b[i].cnt) ans = b[i], pos = i;
	}
	printf("%ld\n", pos);
	for (long i = 1; i <= 100; i++) {
		if (ans.people[i]) {
			printf("%ld", i), ans.p--;
			if (ans.p) printf(" ");
		}
	}
}