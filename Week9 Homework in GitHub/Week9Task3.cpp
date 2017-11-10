#include <cstdio>
#include <cstring>
long n;
char tmp, str[35], target[305];
inline void init(char s[]) {
	char c = getchar();
	long len = 0;
	while (c != ':'&&c != '\n') {
		s[len++] = c, c = getchar();
	}
}
int main() {
	scanf("%ld%c", &n, &tmp);
	for (long i = 1; i <= n; i++) {
		memset(str, '\0', sizeof(str)), init(str);
		memset(target, '\0', sizeof(target)), init(target);
		if (strlen(str) >= strlen(target)) printf("%s\n", "NO"); 
		else {
			long flag = 1, flag1, pos = 0;
			for (long j = 0; j < strlen(str); j++){
				flag1 = 0;
				for (long k = pos; k < strlen(target); k++) {
					if (str[j] == target[k]) { flag1 = 1, pos = k+1; break; }
				}
				if (!flag1) { flag = 0; break; }
			}
			if (flag) printf("%s\n", "YES"); else printf("%s\n", "NO");
		}
	}
}