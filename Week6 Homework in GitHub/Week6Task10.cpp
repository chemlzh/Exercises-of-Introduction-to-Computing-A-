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
��Ŀ����
��һ���׸���Ⱥס������״���������ڣ�������Ϊn*n�ľ���ÿ�����Ϊһ�����䣬���������ס�ˣ�Ҳ���ܿ��š�
�ڵ�һ�죬��Щ��������˵������У��Ժ�ÿ�죬�����е��˻�ʹ���ھӴ�Ⱦ�����У����Ѿ��ò��Ĳ��䣩���շ��䲻�ᴫȾ��
�������m������е�������

����
��һ��һ������n��n������100����ʾ��n*n�����᷿�䡣
��������n�У�ÿ��n���ַ�����.����ʾ��һ��÷���ס�Ž������ˣ���#����ʾ�÷�����ţ���@����ʾ��һ��÷���ס�ŵ����е��ˡ�
��������һ����һ������m��m������100.

���
�����m�죬�����е�����
*/

/*
�ⷨ����ˮ���෨������BFSʵ�֡��롰������⡱��ȣ������ж����ʼ��ͬʱ���࣬�ʲ�����DFS��ֻ����BFS��
*/