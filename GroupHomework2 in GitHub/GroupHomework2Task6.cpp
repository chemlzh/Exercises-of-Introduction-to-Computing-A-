#include <cstdio>
#include <queue>
using namespace std;
struct patient { long x, y, day; }p, p1;
queue <patient> q;
const long d[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };
long n, m, ans, vis[105][105];
char a[105][105], tmp;
int main() {
	scanf("%ld%c", &n, &tmp);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) { 
			scanf("%c", &a[i][j]); 
			if (a[i][j] == '@') { 
				p.x = i; p.y = j; p.day = 1; q.push(p); vis[i][j] = 1; ans++;
			}
		}
		scanf("%c", &tmp);
	}
	scanf("%ld", &m);
	while (!q.empty()) {
		p = q.front(); q.pop(); 
		if (p.day == m) continue;
		for (long i = 1; i <= 4; i++) {
			if (p.x + d[i][0] >= 1 && p.x + d[i][0] <= n&&p.y + d[i][1] >= 1 && p.y + d[i][1] <= n) {
				p1.x = p.x + d[i][0]; p1.y = p.y + d[i][1];
				if (a[p1.x][p1.y] == '.'&&vis[p1.x][p1.y] == 0) { p1.day = p.day + 1; vis[p1.x][p1.y] = 1; q.push(p1); ans++; }
			}
		}
	}
	printf("%ld", ans);
}