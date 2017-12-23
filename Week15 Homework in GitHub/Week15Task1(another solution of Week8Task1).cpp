#include <algorithm>
#include <cstdio>
using namespace std;
long a[205], b[205], ans[205];
long cnta, cntb, p1, p2, c0;
char c;
inline void init(long &count, long x[]) {
	long cnt = 0, tmp = 0;
	while ((c = getchar()) != '\n') {
		if (c == ',') x[++cnt] = tmp, tmp = 0;
		else if (c >= '0'&&c <= '9') tmp = tmp * 10 + c - '0';
	}
	x[++cnt] = tmp, tmp = 0, count = cnt;
	sort(x + 1, x + cnt + 1);
}
int main() {
	init(cnta, a), init(cntb, b), p1 = p2 = 1;
	while (p1 <= cnta && p2 <= cntb) {
		if (a[p1] < b[p2]) p1++;
		else if (a[p1] > b[p2]) p2++;
		else {
			ans[++c0] = a[p1];
			while (a[p1 + 1] == a[p1]) p1++;
			while (b[p2 + 1] == b[p2]) p2++;
			p1++, p2++;
		}
	}
	if (!c0) printf("%s", "NULL");
	else {
		for (long i = 1; i <= c0; i++) {
			printf("%ld", ans[i]);
			if (i != c0) printf("%c", ',');
		}
	}
}