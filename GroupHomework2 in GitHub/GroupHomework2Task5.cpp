#include <cstdio>
double ans;
long n;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) ans += 1 / double(i);
	printf("%.9f", ans);
}