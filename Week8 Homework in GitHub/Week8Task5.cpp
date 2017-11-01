#include <cstdio>
const long month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const char week[7][5] = { "Sun.","Mon.","Tue.","Wed.","Thu.","Fri.","Sat." };
long n, ans;
long y, m, d;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld%ld", &y, &m, &d);
		ans = (y - 1) % 7 + (y / 4 - y / 100 + y / 400) % 7;
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
			if (m <= 2) ans--;
		}
		for (long i = 1; i < m; i++) ans = (ans + month[i]) % 7;
		ans = (ans + d) % 7;
		printf("%s\n", week[ans]);
	}
}