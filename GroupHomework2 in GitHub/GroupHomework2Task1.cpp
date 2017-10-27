#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
struct position{ long x, y, z; }p[15];
struct segment { double d; long s, t; }s[60];
long n, cnt;
inline bool cmp(segment s1,segment s2) {
	if (s1.d > s2.d) return true;
	else if (s1.d < s2.d) return false;
	else if (s1.s < s2.s) return true;
	else if (s1.s > s2.s) return false;
	else if (s1.t < s2.s) return true;
	else if (s1.t > s2.s) return false;
}
inline double dist(position p1, position p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld%ld", &p[i].x, &p[i].y, &p[i].z);
	for (long i = 1; i <= n; i++) {
		for (long j = i + 1; j <= n; j++) {
			cnt++; s[cnt].d = dist(p[i], p[j]); s[cnt].s = i; s[cnt].t = j;
		}
	}
	sort(s + 1, s + cnt + 1, cmp);
	for (long i = 1; i <= cnt; i++) printf("(%ld,%ld,%ld)-(%ld,%ld,%ld)=%.2f\n", p[s[i].s].x, p[s[i].s].y, p[s[i].s].z, p[s[i].t].x, p[s[i].t].y, p[s[i].t].z, s[i].d);
}