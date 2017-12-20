#include <cstdio>
#include <cmath>
int main() {
	for (long i = 32; i <= 99; i++) {
		long a = i*i;
		for (long j = 1; j <= 9; j++) {
			long c = a + j * 1111, r = (long)sqrt(c);
			if (c > 9999) break;
			else if (c == r*r) printf("%ld\n", c);
		}
	}
}