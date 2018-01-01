#include <cstdio>
#include <cstring>
long len, lenr, cyclic, res[70], num[70];
char str[70];
inline long calc(long num1) {
	for (long i = 0; i < len; i++) res[i] += num1 * num[i], res[i + 1] += res[i] / 10, res[i] %= 10;
	long p = len;
	while (res[p] >= 10) res[p + 1] += res[p] / 10, res[p] %= 10, p++;
	while (!res[p]&&p>=len) p--;
	return p + 1;
}
inline bool cmp(long num1) {
	for (long i = 0; i < len; i++) {
		if (num[i] != res[(i + num1) % len]) return false;
	}
	return true;
}
int main() {
	while (scanf("%s", str) != EOF) {
		len = strlen(str), cyclic = 1;
		for (long i = 0; i < len; i++) num[len - i - 1] = str[i] - '0';
		for (long i = len; i >= 2; i--) {
			memset(res, '\0', sizeof(res)), lenr = calc(i);
			if (lenr != len) { printf("%s is not cyclic\n", str), cyclic = 0; break; }
			else {
				long flag = false;
				for (long i = 0; i < len; i++) {
					if (cmp(i)) { flag = true; break; }
				}
				if (!flag) { printf("%s is not cyclic\n", str), cyclic = 0; break; }
			}
		}
		if (cyclic) printf("%s is cyclic\n", str);
	}
}