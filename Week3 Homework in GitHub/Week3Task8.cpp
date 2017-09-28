#include <cstdio>
struct point { long x, y; }p[5];
struct vec { long dx, dy; }v[7];
long n;
long cross(vec v1, vec v2) { return v1.dx*v2.dy - v1.dy*v2.dx; }
int main() {
	while (scanf("%ld%ld%ld%ld%ld%ld%ld%ld", &p[1].x, &p[1].y, &p[2].x, &p[2].y, &p[3].x, &p[3].y, &p[4].x, &p[4].y) != EOF) {
		bool flag = true;
		for (long j = 1; j <= 4; j++) {
			v[j].dx = p[j % 4 + 1].x - p[j].x; v[j].dy = p[j % 4 + 1].y - p[j].y;
		}
		v[5] = v[1]; v[6] = v[2];
		for (long j = 1; j <= 4; j++) {
			if (!cross(v[j], v[j + 1])) { flag = false;  printf("%s\n", "no");  break; }
			if (cross(v[j], v[j + 1]) > 0 && cross(v[j + 1], v[j + 2]) < 0) { flag = false;  printf("%s\n", "no");  break; }
			if (cross(v[j], v[j + 1]) < 0 && cross(v[j + 1], v[j + 2]) > 0) { flag = false;  printf("%s\n", "no");  break; }
		}
		if (flag) printf("%s\n", "yes");
	}
}