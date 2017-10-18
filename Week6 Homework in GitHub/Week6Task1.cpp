#include <cstdio>
long n, k, tmp, a[1005];
void InsertSort(long ins,long cnt,long p[]) {
	long t = cnt;
	while (p[t] > ins&&t > 0) { p[t + 1] = p[t]; t--; }
	p[t + 1] = ins;
}
int main() {
	scanf("%ld", &n);
	a[0] = 2147483647L;
	for (long i = 1; i <= n; i++) { scanf("%ld", &tmp); InsertSort(tmp, i-1, a); }
	scanf("%ld", &k);
	for (long i = n; i >= n - k + 1; i--) printf("%ld\n", a[i]);
}