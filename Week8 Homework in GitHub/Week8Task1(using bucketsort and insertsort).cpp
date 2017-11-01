#include <algorithm>
#include <cstdio>
using namespace std;
long bucket[10005], b[205], tmp, cnt1, flag;
char c;
inline void insert(long num, long &mcnt, long m[]) {
	long p = mcnt;
	while (p > 0 && num < m[p]) { m[p + 1] = m[p]; p--; }
	m[p + 1] = num; mcnt++;
}
int main() {
	for (;;) {
		c = getchar();
		if (c >= '0'&&c <= '9') tmp = tmp * 10 + c - '0';
		else { bucket[tmp]++; tmp = 0; }
		if (c == '\n') break;
	}
	for (;;) {
		c = getchar();
		if (c >= '0'&&c <= '9') tmp = tmp * 10 + c - '0';
		else {
			if (bucket[tmp]) { flag = 1, bucket[tmp] = 0, insert(tmp, cnt1, b); }
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