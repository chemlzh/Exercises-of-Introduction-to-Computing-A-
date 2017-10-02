#include <cstdio>
#include <cstring>
long N, n, x, y, map[25][25];
long check(long x0,long y0,long player) {
	long cnt = 1;
	for (long i = 1; i <= 4; i++) { if (x0 + i <= N&&map[x0 + i][y0] == player) cnt++; else break; }
	for (long i = 1; i <= 4; i++) { if (x0 - i >= 0 && map[x0 - i][y0] == player) cnt++; else break; }
	if (cnt >= 5) return 1;
	cnt = 1;
	for (long i = 1; i <= 4; i++) { if (y0 + i <= N&&map[x0][y0 + i] == player) cnt++; else break; }
	for (long i = 1; i <= 4; i++) { if (y0 - i >= 0 && map[x0][y0 - i] == player) cnt++; else break; }
	if (cnt >= 5) return 1;
	cnt = 1;
	for (long i = 1; i <= 4; i++) { if (y0 + i <= N&& x0 + i <= N&&map[x0 + i][y0 + i] == player) cnt++; else break; }
	for (long i = 1; i <= 4; i++) { if (y0 - i >= 0 && x0 - i >= 0 && map[x0 - i][y0 - i] == player) cnt++; else break; }
	if (cnt >= 5) return 1;
	cnt = 1;
	for (long i = 1; i <= 4; i++) { if (y0 - i >= 0 && x0 + i <= N&&map[x0 + i][y0 - i] == player) cnt++; else break; }
	for (long i = 1; i <= 4; i++) { if (y0 + i <= N && x0 - i >= 0 && map[x0 - i][y0 + i] == player) cnt++; else break; }
	if (cnt >= 5) return 1;
	return 0;
}
int main() {
	scanf("%ld%ld", &N, &n);
	memset(map, -1, sizeof(map));
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &x, &y);	map[x][y] = (i + 1) % 2;
		if (check(x, y, map[x][y])) {
			printf("%ld %ld", i, (i + 1) % 2); return 0;
		}
	}
}