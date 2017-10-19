#include <cstdio>
long n,map[105][105],vis[105][105],area,cir;
void floodfill(long x, long y) {
	vis[x][y] = 1; area++;
	if (x == 1 || y == 1 || x == n || y == n) cir++;
	else if (map[x - 1][y] > 50 || map[x + 1][y] > 50 || map[x][y - 1] > 50 || map[x][y + 1] > 50) cir++;
	if (x > 1 && map[x - 1][y] <= 50 && vis[x - 1][y] == 0) floodfill(x - 1, y);
	if (x < n&&map[x + 1][y] <= 50 && vis[x + 1][y] == 0) floodfill(x + 1, y);
	if (y > 1 && map[x][y - 1] <= 50 && vis[x][y - 1] == 0) floodfill(x, y - 1);
	if (y < n&&map[x][y + 1] <= 50 && vis[x][y + 1] == 0) floodfill(x, y + 1);
}
int main() {
	scanf("%ld",&n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) scanf("%ld", &map[i][j]);
	}
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) if (!vis[i][j] && map[i][j] <= 50) floodfill(i, j);
	}
	printf("%ld %ld", area, cir);
}