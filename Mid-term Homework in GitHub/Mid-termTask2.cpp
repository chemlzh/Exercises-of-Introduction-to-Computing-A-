#include <cstdio>
const long M = 23*28*33;
long ans, d, a[4], w[4] = { 0,23,28,33 };
void ExtendedEuclidean(long a,long b,long& x,long& y) {
	if (!b) { x = 1; y = 0; return; }
	else { ExtendedEuclidean(b, a%b, y, x); y -= a / b*x; }
}
long ChineseRemainder(long a[], long w[], long cnt) {
	long now = 0, x, y, m;
	for (long i = 1; i <= cnt; i++) {
		m = M / w[i]; ExtendedEuclidean(w[i],m,x,y);
		now = (now + m*y*a[i]) % M;
	}
	return (now + M) % M;
}
int main() {
	while (scanf("%ld%ld%ld%ld",&a[1],&a[2],&a[3],&d) != EOF) {
		if (a[1] < 0 || a[2] < 0 || a[3] < 0 || d < 0) break;
		else { 
			a[1] %= w[1]; a[2] %= w[2]; a[3] %= w[3];
			ans = ChineseRemainder(a, w, 3) - d;
			if (ans <= 0) ans += M;
			printf("%ld\n", ans);
		}
	}
}

//The origin source is HDU 1370 and POJ 1006.