#include <algorithm>
#include <cstdio>
using namespace std;
long tmp, a[205], ans[205], cnt1, cnt2;
char c;
void Insert(long num, long cnt, long ins[]) {
	long pos = cnt ;
	ins[0] = num;
	while (pos >= 0 && num < ins[pos]) { ins[pos + 1] = ins[pos];  pos--; }
	ins[pos + 1] = ins[0];
}
int main() {
	for (;;) {
		scanf("%ld%c", &a[++cnt1], &c);
		if (c == '\n') break;
	}
	sort(a + 1, a + cnt1 + 1);
	for (;;) {
		scanf("%ld%c", &tmp, &c);
		if (binary_search(a + 1, a + cnt1 + 1, tmp) && (!binary_search(ans + 1, ans + cnt2 + 1, tmp))) {
			Insert(tmp, cnt2, ans);  cnt2++;
		}
		if (c == '\n') break;
	}
	if (!cnt2) printf("%s", "NULL");
	else {
		for (long i = 1; i <= cnt2; i++) { printf("%ld", ans[i]); if (i != cnt2) printf("%c", ','); }
	}
}