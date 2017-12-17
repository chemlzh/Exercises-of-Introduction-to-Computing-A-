#include <cstdio>
#include <queue>
using namespace std;
struct pos { long x, y; }p1, p2;
long n, m, tmp, cnt, nows, maxs;
long map[105][105], vis[105][105];
queue<pos> q;
int main() {
	scanf("%ld%ld", &m, &n);
	for (long i = 1; i <= m; i++) {
		for (long j = 1; j <= n; j++) {
			scanf("%ld", &tmp);
			if (tmp >= 8) tmp -= 8, map[2 * i][2 * j - 1] = 1;
			if (tmp >= 4) tmp -= 4, map[2 * i - 1][2 * j] = 1;
			if (tmp >= 2) tmp -= 2, map[2 * (i - 1)][2 * j - 1] = 1;
			if (tmp >= 1) tmp -= 1, map[2 * i - 1][2 * (j - 1)] = 1;
		}
	}
	for (long i = 1; i <= m; i++) {
		for (long j = 1; j <= n; j++) {
			if (!vis[2 * i - 1][2 * j - 1]) {
				cnt++, nows = 0;
				p1.x = 2 * i - 1, p1.y = 2 * j - 1, vis[p1.x][p1.y] = 1, q.push(p1);
				while (!q.empty()) {
					p2 = q.front(), q.pop(),  nows++;
					if (!map[p2.x - 1][p2.y] && !vis[p2.x - 2][p2.y]) {
						p1.x = p2.x - 2, p1.y = p2.y, vis[p1.x][p1.y] = 1, q.push(p1);
					}
					if (!map[p2.x][p2.y - 1] && !vis[p2.x][p2.y - 2]) {
						p1.x = p2.x, p1.y = p2.y - 2, vis[p1.x][p1.y] = 1, q.push(p1);
					}
					if (!map[p2.x + 1][p2.y] && !vis[p2.x + 2][p2.y]) {
						p1.x = p2.x + 2, p1.y = p2.y, vis[p1.x][p1.y] = 1, q.push(p1);
					}
					if (!map[p2.x][p2.y + 1] && !vis[p2.x][p2.y + 2]) {
						p1.x = p2.x, p1.y = p2.y + 2, vis[p1.x][p1.y] = 1, q.push(p1);
					}
				}
				if (nows > maxs) maxs = nows;
			}
		}
	}
	printf("%ld\n%ld\n", cnt, maxs);
}