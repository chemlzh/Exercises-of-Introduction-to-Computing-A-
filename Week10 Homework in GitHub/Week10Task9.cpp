#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct dict{ char str[505]; }d[205];
long n, f[505][505], lenS, lenT, ans, cnt;
char c, S[505], T[505];

int main() {
	scanf("%s", S), scanf("%ld%c", &n, &c), lenS = strlen(S);
	for (long i = 1; i <= n; i++) {
		scanf("%s", T), lenT = strlen(T), memset(f, 0, sizeof(f));
		for (long x = 0; x <= lenS; x++) f[x][0] = x;
		for (long y = 0; y <= lenT; y++) f[0][y] = y;
		for (long x = 1; x <= lenS; x++) {
			for (long y = 1; y <= lenT; y++) {
				long cost = (S[x - 1] == T[y - 1]) ? 0 : 2;
				f[x][y] = min(f[x - 1][y] + 1, min(f[x][y - 1] + 1, f[x - 1][y - 1] + cost));
			}
		}
		if (ans > f[lenS][lenT] || cnt == 0) {
			ans = f[lenS][lenT], cnt = 1, strcpy(d[1].str, T);
		}
		else if (ans == f[lenS][lenT]) strcpy(d[++cnt].str, T);
	}
	for (long i = 1; i <= cnt; i++) printf("%s\n", d[i].str);
}