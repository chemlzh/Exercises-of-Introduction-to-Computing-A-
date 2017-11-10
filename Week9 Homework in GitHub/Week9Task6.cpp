#include <cmath>
#include <cstdio>
#include <cstring>
long N, len, flag, tmp, ans, f[10001];
char num[10];
int main() {
	scanf("%ld", &N);
	for (long i=2; i <= (long)sqrt(N); i++) {
		if (f[i]) continue;
		for (long j = 2 * i; j <= N; j += i) f[j] = 1;
	}
	for (long i = 11; i <= N; i++) {
		if (f[i]) continue;
		memset(num, '\0', sizeof(num)), len = 0, flag = 1, tmp = i;
		while (tmp) num[len++] = tmp % 10+'0', tmp /= 10;
		for (long i = 0; i < len / 2; i++) {
			if (num[i] != num[len - i - 1]) flag = 0;
		}
		if (flag) ans++;
	}
	printf("%ld", ans);
}