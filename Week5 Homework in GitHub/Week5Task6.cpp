#include <cstdio>
long n, ans, patient, tmp = 0x7fffffff;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &patient);
		if (tmp > patient) { tmp = patient; ans = i; }
	}
	printf("%ld", ans);
}