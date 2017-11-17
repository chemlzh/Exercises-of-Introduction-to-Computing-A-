#include <cstdio>
#include <cstring>
long n, len, now, cnt;
char c, str[1005];
int main() {
	scanf("%ld%c", &n, &c);
	for (long i = 1; i <= n; i++) {
		scanf("%s", str), len = strlen(str);
		now = str[0] - '0', cnt = 1;
		for (long j = 1; j < len; j++) {
			if (str[j] != str[j - 1]) printf("%ld%ld", cnt, now), now = str[j] - '0', cnt = 1;
			else cnt++;
		}
		printf("%ld%ld\n", cnt, now);
	}
}