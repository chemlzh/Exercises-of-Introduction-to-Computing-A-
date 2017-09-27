#include <cstdio>
#include <cmath>
const double pi = 3.1415926;
long n;
double r,x[4], y[4];
double angle(double x,double y) {
	if (x == 0 && y > 0) return pi / 2;
	else if (x == 0 && y < 0) return 3 * pi / 2;
	else if (x > 0 && y >= 0) return atan(y / x);
	else if (x > 0 && y < 0) return 2*pi+atan(y / x);
	else if (x < 0 && y >= 0) return pi+atan(y / x);
	else if (x < 0 && y < 0) return pi + atan(y / x);
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		double a[4],temp;
		scanf("%lf%lf%lf%lf%lf%lf%lf", &r, &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
		if ((!x[1] && !y[1]) || (!x[2] && !y[2]) || (!x[3] && !y[3])) printf("%s", "No");
		else { 
			a[1] = angle(x[1], y[1]); a[2] = angle(x[2], y[2]); a[3] = angle(x[3], y[3]); 
			for (long j = 1; j <= 2; j++) {
				for (long k = j; k <= 3; k++) if (a[j] > a[j + 1]) { temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp; }
			}
			if (a[2] - a[1] >= 4 * pi / 3 || a[3] - a[2] >= 4 * pi / 3 || a[1] - a[3] >= -2 * pi / 3) printf("%s", "No");
			else printf("%s", "Yes");
		}
		if (i != n) printf("\n");
	}
}