#include <cstdio>
long n;
double mix,now;
int main() {
	double a, b;
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%lf%lf", &a, &b);
		if (i == 1) mix = b / a;
		else {
			now = b / a;
			if (mix - now > 0.05) printf("%s", "worse");
			else if (mix - now < -0.05) printf("%s", "better");
			else printf("%s", "same");
			if (i != n) printf("\n");
		}
	}
}