#include <cstdio>
struct vec { long x, y; }v[4];
long x[5], y[5];
long cross(vec v1, vec v2) {
	return v1.x*v2.y - v1.y*v2.x;
}
int main() {
	while (scanf("%ld%ld%ld%ld%ld%ld%ld%ld", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]) != EOF) {
		bool flag = true;
		for (long i = 0; i <= 3; i++) { v[i].x = x[(i + 1) % 4] - x[i]; v[i].y = y[(i + 1) % 4] - y[i]; }
		for (long i = 0; i <= 3; i++) {
			if (!cross(v[i], v[(i + 1) % 4])) { printf("%s\n", "no"); flag = false; break; }
			else if (cross(v[i], v[(i + 1) % 4]) < 0 && cross(v[(i + 1) % 4], v[(i + 2) % 4]) > 0) { printf("%s\n", "no"); flag = false; break; }
			else if (cross(v[i], v[(i + 1) % 4]) > 0 && cross(v[(i + 1) % 4], v[(i + 2) % 4]) < 0) { printf("%s\n", "no"); flag = false; break; }
		}
		if (flag) printf("%s\n", "yes");
	}
}