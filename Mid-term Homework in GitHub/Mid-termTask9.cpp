#include <cstdio>
long N;
double W, H, A, REE;
char gen, tmp;
int main() {
	scanf("%ld%c", &N, &tmp);
	for (long i = 1; i <= N; i++) {
		scanf("%c%lf%lf%lf%c", &gen, &W, &H, &A, &tmp);
		if (gen == 'F') REE += 655 + 9.6*W + 1.7*H - 4.7*A;
		else if (gen == 'M') REE += 66 + 13.7*W + 5.0*H - 6.8*A;
	}
	printf("%.1f", REE);
}