#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct number { char digit[105]; }f[105][105], num, tmp;
long n, numlen, pos = 0;
int main() {
	scanf("%s %ld", &num.digit, &n);
	f[1][0].digit[0] = num.digit[0];
	numlen = strlen(num.digit);
	for (long i = 2; i <= numlen; i++) {
		strcpy(f[i][0].digit, f[i - 1][0].digit), f[i][0].digit[i - 1] = num.digit[i - 1];
		for (long j = 1; j < min(i, n + 1); j++) {
			memset(tmp.digit, '\0', sizeof(tmp.digit));
			strcpy(f[i][j].digit, f[i - 1][j - 1].digit);
			strcpy(tmp.digit, f[i - 1][j].digit), tmp.digit[i - j - 1] = num.digit[i - 1];
			if (strcmp(f[i][j].digit, tmp.digit) == 1) strcpy(f[i][j].digit, tmp.digit);
		}
	}
	while (f[numlen][n].digit[pos] == '0') pos++;
	if (pos == numlen - n) printf("%c", '0');
	else {
		for (long i = pos; i < numlen - n; i++) printf("%c", f[numlen][n].digit[i]);
	}
}