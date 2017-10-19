#include <cstdio>
#include <queue>
using namespace std;
struct patient { long x, y, day; }pp[10005], t, t1;
queue<patient> q;
long n, m, pnum, ans;
bool vis[105][105];
char tmp, map[105][105];
int main() {
	scanf("%ld",&n); 
	for (long i = 1; i <= n; i++) {
		scanf("%c", &tmp); 
		for (long j = 1; j <= n; j++) { 
			scanf("%c", &map[i][j]);
			if (map[i][j] == '@') { pnum++; pp[pnum].x = i; pp[pnum].y = j; pp[pnum].day = 1; }
		}
	}
	scanf("%ld", &m);
	for (long i = 1; i <= pnum; i++) { q.push(pp[i]); vis[pp[i].x][pp[i].y] = 1; }
	while (!q.empty()) {
		t = q.front(); q.pop(); ans++; 
		if (t.day == m) continue;
		t1.day = t.day + 1;
		if (t.x > 1 && vis[t.x - 1][t.y] == 0 && map[t.x - 1][t.y] != '#') { t1.x = t.x - 1; t1.y = t.y; vis[t1.x][t1.y] = 1; q.push(t1); }
		if (t.x < n && vis[t.x + 1][t.y] == 0 && map[t.x + 1][t.y] != '#') { t1.x = t.x + 1; t1.y = t.y; vis[t1.x][t1.y] = 1; q.push(t1); }
		if (t.y > 1 && vis[t.x][t.y - 1] == 0 && map[t.x][t.y - 1] != '#') { t1.x = t.x; t1.y = t.y - 1; vis[t1.x][t1.y] = 1; q.push(t1); }
		if (t.y < n && vis[t.x][t.y + 1] == 0 && map[t.x][t.y + 1] != '#') { t1.x = t.x; t1.y = t.y + 1; vis[t1.x][t1.y] = 1; q.push(t1); }
	}
	printf("%ld", ans);
}
/*
题目描述
有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。
在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。
请输出第m天得流感的人数。

输入
第一行一个数字n，n不超过100，表示有n*n的宿舍房间。
接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。
接下来的一行是一个整数m，m不超过100.

输出
输出第m天，得流感的人数
*/

/*
解法：大水漫灌法，采用BFS实现。与“肿瘤检测”相比，本题有多个起始点同时漫灌，故不能用DFS，只能用BFS。
*/