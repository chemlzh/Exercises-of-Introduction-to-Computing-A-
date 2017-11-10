#include <cstdio>
#include <queue>
using namespace std;
struct pos { long r, c; }s, e, t1, t2;
queue<pos> q;
long m, n, flag, map[55][55], vis[55][55];
int main() {
	scanf("%ld%ld", &m, &n);
	for (long i = 1; i <= m; i++) {
		for (long j = 1; j <= n; j++) {
			scanf("%ld", &map[i][j]);
			if (map[i][j] == 2) s.r = i, s.c = j;
			else if (map[i][j] == 3) e.r = i, e.c = j;
		}
	}
	q.push(s), vis[s.r][s.c] = 1;
	while (!q.empty()) {
		t1 = q.front(), q.pop();
		if (map[t1.r][t1.c] == 3) { flag = 1; break; }
		if ((map[t1.r - 1][t1.c] != 1) && (!vis[t1.r - 1][t1.c]) && t1.r > 1)
			t2.r = t1.r - 1, t2.c = t1.c, vis[t2.r][t2.c] = 1, q.push(t2);
		if ((map[t1.r][t1.c + 1] != 1) && (!vis[t1.r][t1.c + 1]) && t1.c < n)
			t2.r = t1.r, t2.c = t1.c + 1, vis[t2.r][t2.c] = 1, q.push(t2);
		if ((map[t1.r + 1][t1.c] != 1) && (!vis[t1.r + 1][t1.c]) && t1.r < m)
			t2.r = t1.r + 1, t2.c = t1.c, vis[t2.r][t2.c] = 1, q.push(t2);
		if ((map[t1.r][t1.c - 1] != 1) && (!vis[t1.r][t1.c - 1]) && t1.c > 1)
			t2.r = t1.r, t2.c = t1.c - 1, vis[t2.r][t2.c] = 1, q.push(t2);
	}
	if (flag) printf("%s", "Yes"); else printf("%s", "No");
}