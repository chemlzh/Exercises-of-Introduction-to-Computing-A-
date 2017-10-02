#include <cstdio>
long n, gold, silver, bronze, total;
int main() {
	long g, s, b;
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld%ld", &g, &s, &b);
		gold += g; silver += s; bronze += b;
	}
	total = gold + silver + bronze;
	printf("%ld %ld %ld %ld", gold, silver, bronze, total);
}