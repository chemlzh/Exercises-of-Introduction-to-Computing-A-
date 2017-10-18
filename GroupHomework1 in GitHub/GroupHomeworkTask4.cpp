#include <cstdio>
long n;
double st, tmp, a, b;
int main() {
	scanf("%ld", &n);
	scanf("%lf%lf", &a, &b); st = b / a;
	for (long i = 1; i <= n - 1; i++) {
		scanf("%lf%lf", &a, &b); tmp = b / a;
		if (tmp - st > 0.05) printf("%s\n", "better");
		else if (tmp - st < -0.05) printf("%s\n", "worse");
		else printf("%s\n", "same");
	}
}