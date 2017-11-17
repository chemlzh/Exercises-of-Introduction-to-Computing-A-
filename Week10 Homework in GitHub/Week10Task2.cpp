#include <cstdio>
#include <cstring>
long n, flag, len, bi[33];
char c;
int main() {
	c = getchar();
	for (;;) {
		if (c >= '0'&&c <= '9') n = n * 10 + c - '0';
		else if (c == '\n') {
			len = 1;
			while (n) bi[len - 1] = n % 2, n /= 2, len++;
			len--;
			if (flag) {
				for (long i = 0; i < 32; i++) bi[i] = (!bi[i]);
				bi[0]++;
				for (long i = 0; i < 32; i++) bi[i + 1] += bi[i] / 2, bi[i] %= 2;
			}
			for (long i = 31; i >= 0; i--) printf("%c", bi[i] + '0');
			printf("\n"), flag = 0, n = 0, memset(bi, 0, sizeof(bi));
		}
		else if (c == '-') flag = 1;
		else break;
		c = getchar();
	}
}