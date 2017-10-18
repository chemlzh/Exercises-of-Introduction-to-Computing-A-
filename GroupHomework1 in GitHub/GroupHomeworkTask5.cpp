#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi = 3.1415926;
long t;
double r, x[4], y[4];
double a[4];
inline double angle(double x,double y) {
	if (x == 0 && y > 0) return pi / 2;
	if (x == 0 && y < 0) return 3 * pi / 2;
	if (y == 0 && x > 0) return 0;
	if (y == 0 && x < 0) return pi;
	if (x > 0 && y > 0) return atan(y / x);
	if (x < 0 && y>0) return atan(y / x) + pi;
	if (x < 0 && y < 0) return atan(y / x) + pi;
	if (x > 0 && y < 0) return atan(y / x) + 2 * pi;
}
int main() {
	scanf("%ld", &t);
	for (long i = 1; i <= t; i++) {
		scanf("%lf%lf%lf%lf%lf%lf%lf", &r, &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
		if ((!x[1] && !y[1]) || (!x[2] && !y[2]) || (!x[3] && !y[3])) printf("%s\n", "No");
		else {
			bool flag = true;
			for (long j = 0; j <= 2; j++) a[j] = angle(x[j+1], y[j+1]);
			sort(a, a + 3);
			for (long j = 0; j <= 2; j++) {
				double tmp = a[(j + 2) % 3] - a[j];
				if (tmp < 0)  tmp += 2 * pi;
				if (tmp <= 2 * pi / 3) { printf("%s\n", "No"); flag = false; break;  }
			}
			if (flag) printf("%s\n", "Yes");
		}
	}
}