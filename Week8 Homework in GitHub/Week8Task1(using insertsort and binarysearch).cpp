#include <algorithm>
#include <cstdio>
using namespace std;
long a[205], b[205],tmp, cnt, cnt1, flag;
char c;
inline void insert(long num,long &mcnt,long m[]) {
	long p = mcnt;
	while (p > 0 && num < m[p]) { m[p + 1] = m[p]; p--; }
	m[p + 1] = num; mcnt++;
}
int main() {
	for (;;) {
		c = getchar();
		if (c >= '0'&&c <= '9') tmp = tmp * 10 + c - '0';
		else { insert(tmp, cnt, a), tmp = 0; }
		if (c == '\n') break;
	}
	for (;;) {
		c = getchar();
		if (c >= '0'&&c <= '9') tmp = tmp * 10 + c - '0';
		else { 
			if (binary_search(a + 1, a + cnt + 1, tmp) && (!binary_search(b + 1, b + cnt1 + 1, tmp))) { flag = 1, insert(tmp, cnt1, b); }
			tmp = 0;
		}
		if (c == '\n') break;
	}
	if (!flag) printf("%s", "NULL");
	else {
		for (long i = 1; i < cnt1; i++) printf("%ld,", b[i]);
		printf("%ld", b[cnt1]);
	}
}