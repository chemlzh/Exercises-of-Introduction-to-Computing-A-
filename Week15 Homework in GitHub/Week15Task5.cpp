#include <cstdio>
#include <cstring>
char c, s[3][305];
long cnt, posl = -1, posr = -1, len[3];
int main() {
	while ((c = getchar()) != '\n') {
		if (c == ',') cnt++;
		else s[cnt][len[cnt]] = c, len[cnt]++;
	}
	for (long i = 0; i <= len[0] - len[1]; i++) {
		long flag = 1;
		for (long j = 0; j < len[1]; j++) {
			if (s[0][j + i] != s[1][j]) flag = 0;
		}
		if (flag) { posl = i + len[1] - 1; break; }
	}
	if (posl == -1) { printf("%ld", -1); return 0; }
	for (long i = len[0] - len[2]; i >= 0; i--) {
		long flag = 1;
		for (long j = 0; j < len[2]; j++) {
			if (s[0][j + i] != s[2][j]) { flag = 0; break; }
		}
		if (flag) { posr = i; break; }
	}
	if (posr == -1) printf("%ld", -1); 
	else if (posl>=posr) printf("%ld", -1);
	else printf("%ld", posr - posl - 1);
}