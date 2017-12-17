#include <cstdio>
long n, ans, p[100005], q[100005];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld", &p[i]);
	q[1] = 1;
	for (long i = 2; i <= n; i++) {
		if (p[i] <= p[i - 1]) q[i] = 1;
		else q[i] = q[i - 1] + 1;
	}
	for (long i = n - 1; i >= 1; i--) {
		if (p[i] > p[i + 1] && q[i]<=q[i+1]) q[i] = q[i + 1] + 1;
	}
	for (long i = 1; i <= n; i++) ans += q[i];
	printf("%ld", ans);
}