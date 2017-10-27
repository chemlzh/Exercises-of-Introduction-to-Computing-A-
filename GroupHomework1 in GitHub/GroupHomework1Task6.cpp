#include <cmath>
#include <cstdio>
const long MaxNum = 5005;
long m, k, cnt, a[MaxNum];
int main() {
	scanf("%ld%ld", &m, &k);
	a[1] = 1;
	for (long i = 2; i <= (long)sqrt(MaxNum); i++) {
		if (!a[i]) {
			for (long j = 2; j <= MaxNum / i; j++) a[j*i] = 1;
		}
	}
	for (long i = m + 1; i <= MaxNum; i++) {
		if (!a[i]) {
			cnt++; printf("%ld", i);
			if (cnt < k) printf(" "); else break;
		}
	}
}