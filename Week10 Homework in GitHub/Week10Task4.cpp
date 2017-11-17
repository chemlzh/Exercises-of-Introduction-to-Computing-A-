#include <cstdio>
long n, m;
inline long gcd(long a, long b) {
	if (a == 0 || b == 0) return 0;
	long a1 = a, b1 = b, tmp;
	while (b1>0) {
		tmp = a1%b1, a1 = b1, b1 = tmp;
	}
	return a1;
}
int main() {
	scanf("%ld,%ld", &n, &m);
	if (n != 0 && m != 0) printf("%ld", n*m / gcd(n, m));
}