#include <algorithm>
#include <cstdio>
using namespace std;
struct zone { long l, r; }a[50005];
long n, l0, r0;
inline long cmp(zone x, zone y) {
	if (x.l < y.l) return true;
	else if (x.l > y.l) return false;
	else if (x.r < y.r) return true;
	else return false;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld", &a[i].l, &a[i].r);
	sort(a + 1, a + n + 1, cmp);
	l0 = a[1].l, r0 = a[1].r;
	for (long i = 2; i <= n; i++) {
		if (a[i].l > r0) { printf("%s", "no"); return 0; }
		if (a[i].r > r0) r0 = a[i].r;
	}
	printf("%ld %ld", l0, r0);
}