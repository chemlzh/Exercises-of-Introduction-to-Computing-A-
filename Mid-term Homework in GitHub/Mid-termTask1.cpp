#include <cmath>
#include <cstdio>
const double pi = 3.14159;
double h, r, v;
long ans;
int main() {
	scanf("%lf%lf", &h, &r);
	v = pi*r*r*h;
	ans = (long)ceil(20000/v);
	printf("%ld",ans);
}