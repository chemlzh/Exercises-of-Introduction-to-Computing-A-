#include <cstdio>
long n, c = 2;
int main() {
	scanf("%ld", &n), printf("%ld%c", n, '=');
	while (c <= n) {
		while (n % c == 0) {
			n /= c, printf("%ld", c);
			if (n > 1) printf("*");
		}
		c++;
	}
}