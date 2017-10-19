#include <cstdio>
long n, k, cnt, a[100005];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld", &a[i]);
	scanf("%ld", &k);
	for (long i = 1; i <= n; i++) {
		if (a[i] != k) a[++cnt] = a[i]; 
	}
	for (long i = 1; i <= cnt; i++) {
		printf("%ld", a[i]);
		if (i < cnt) printf(" ");
	}
}