#include <cstdio>
long n;
int main() {
	scanf("%ld", &n);
	while (n > 1) {
		if (n % 2) printf("%ld*3+1=%ld\n", n, 3 * n + 1), n = 3 * n + 1;
		else printf("%ld/2=%ld\n", n, n / 2), n /= 2;
	}
	printf("%s", "End");
}