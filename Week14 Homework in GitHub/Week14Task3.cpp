#include <cstdio>
#include <cstring>
long n, m, match[1005];
char dict[105][25], str[1005];
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= n; i++) scanf("%s", &dict[i]);
	for (long i = 1; i <= m; i++) {
		scanf("%s", str);
		memset(match, 0, sizeof(match));
		match[0] = 1;
		for (long j = 0; j < strlen(str); j++) {
			if (!match[j]) continue;
			for (long k = 1; k <= n; k++) {
				long flag = 1;
				for (long l = 0; l < strlen(dict[k]); l++) {
					if (str[j + l] != dict[k][l]) { flag = 0; break; }
				}
				if (flag) match[j + strlen(dict[k])] = 1;
			}
		}
		if (match[strlen(str)]) printf("%s\n", "Yes");
		else printf("%s\n", "No");
	}
}