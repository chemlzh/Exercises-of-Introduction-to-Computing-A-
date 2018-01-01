#include <cstdio>
#include <cstring>
struct pos { long x, y; }s, t;
const long step[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
long n, m, d, vis[205][205];
char c, map[205][205];
inline bool judge(pos p) {
	if (p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= m && map[p.x][p.y] != '#') return true;
	return false;
}
inline bool dfs(pos now,long dir) {
	if (now.x == t.x&&now.y == t.y) return true;
	else {
		pos tmp;
		for (long i = -1; i < 3; i++) {
			tmp.x = now.x + step[(dir + i + 4) % 4][0];
			tmp.y = now.y + step[(dir + i + 4) % 4][1];
			if (judge(tmp)) {
				if (vis[tmp.x][tmp.y] == (dir + i + 4) % 4) return false;
				else {
					vis[tmp.x][tmp.y] = (dir + i + 4) % 4;
					return dfs(tmp, (dir + i + 4) % 4);
				}
			}
		}
		return false;
	}
}
inline void InitDir() {
	if (c == 'N') d = 0;
	else if (c == 'E') d = 1;
	else if (c == 'S') d = 2;
	else if (c == 'W') d = 3;
}
int main() {
	while (scanf("%ld%ld", &n, &m) != EOF) {
		scanf("%c", &c);
		for (long i = 1; i <= n; i++) {
			for (long j = 1; j <= m; j++) {
				scanf("%c", &map[i][j]), vis[i][j] = -1;
				if (map[i][j] == 'S') s.x = i, s.y = j;
				else if (map[i][j] == 'T') t.x = i, t.y = j;
			}
			scanf("%c", &c);
		}
		scanf("%c", &c), InitDir();
		if (dfs(s, d)) printf("%s\n", "YES");
		else printf("%s\n", "NO");
	}
}