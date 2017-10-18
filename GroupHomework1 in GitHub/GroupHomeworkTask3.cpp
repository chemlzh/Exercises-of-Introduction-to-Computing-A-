#include <cstdio>
long n;
double e = 1, fac = 1;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) { fac *= i; e += 1 / fac; }
	printf("%.6f", e);
}