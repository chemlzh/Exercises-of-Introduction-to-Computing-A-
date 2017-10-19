#include <cstdio>
long N, tmp;
int main() {
	scanf("%ld", &N);
	for (long i = 1; i <= N; i++) {
		long cnt = 0;
		scanf("%ld", &tmp);
		while (tmp) { cnt += tmp % 2; tmp /= 2; }
		printf("%ld\n", cnt);
	}
}