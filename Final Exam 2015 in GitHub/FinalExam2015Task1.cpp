#include <cstdio>
#include <cstring>
const char dict[3][4] = { "er","ly","ing" };
const long dlen[3] = { 2,2,3 };
char str[40];
long n, len;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%s", str), len = strlen(str);
		for (long j = 0; j <= 2; j++) {
			long flag = 1;
			for (long k = 0; k < dlen[j]; k++) {
				if (dict[j][k] != str[len - dlen[j] + k]) { flag = 0; break; }
			}
			if (flag) {
				for (long k = 0; k < len - dlen[j]; k++) printf("%c", str[k]);
				printf("\n"); break;
			}
		}
	}
}