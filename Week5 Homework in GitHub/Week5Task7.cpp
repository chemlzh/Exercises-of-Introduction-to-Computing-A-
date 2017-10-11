#include <algorithm>
#include <cstdio>
using namespace std;
struct event{long start, end; }e[100005];
long n, LastTail, ans;
inline bool cmp(event e1,event e2) {
	if (e1.end < e2.end) return true;
	else if (e1.end > e2.end) return false;
	else if (e1.start > e1.start) return true;
	return false;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld", &e[i].start, &e[i].end);
	sort(e + 1, e + n + 1, cmp);
	for (long i = 1; i <= n; i++) {
		if (e[i].start >= LastTail) {	ans++;	LastTail = e[i].end;  }
	}
	printf("%ld", ans);
}

/*解释：本题是线段最大不相交覆盖问题，解法是对线段的右端点进行升序排序，每加入一个线段，
如果加入以后不会跟之前的线段产生公共部分，那么就加入，否则就继续判断后面的线段。
贪心证明：因为需要尽量多的独立的线段，所以每个线段都尽可能的小，对于同一右端点，左端点越大，线段长度越小。
那么为什么要对右端点进行排序呢？如果左端点进行排序，那么右端点是多少并不知道，
那么每一条线段都不能对之前所有的线段进行一个总结，那么这就明显不满足贪心的最优化结构了。
*/