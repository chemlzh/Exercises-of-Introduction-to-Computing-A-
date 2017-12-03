#include <cstdio>
long n, a, b, t;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &a, &b);
		while (b != 0) t = a%b, a = b, b = t;
		printf("%ld\n", a);
	}
}