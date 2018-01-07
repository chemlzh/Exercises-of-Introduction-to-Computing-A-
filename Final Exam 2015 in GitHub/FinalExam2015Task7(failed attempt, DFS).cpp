#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long n, ans, a[25], vis[25], pre[25], post[25];
char op[25];
inline long calc(char op0, long n1, long n2) {
	if (op0 == '+') return n1 + n2; else return n1 * n2;
}
inline void dfs(long step, long ban){
	if (step == n - 1) ans = max(ans, pre[ban]);
	else {
		long t1, t2, p1, p2;
		for (long i = 0; i < n; i++) {
			if (!vis[i] && i != ban) {
				vis[i] = 1, p1 = (i + n - 1) % n, p2 = (i + 1) % n;
				while (vis[p1]) p1 = (p1 + n - 1) % n;
				while (vis[p2]) p2 = (p2 + 1) % n;
				t1 = pre[p2], t2 = post[p1], pre[p2] = post[p1] = calc(op[i], pre[i], post[i]);
				dfs(step + 1, ban);
				vis[i] = 0, pre[p2] = t1, post[p1] = t2;
			}
		}
	}
}
int main() {
	scanf("%ld", &n);
	for (long i = 0; i < n; i++) scanf("%ld %c", &a[i], &op[i]);
	for (long i = 0; i < n; i++) pre[i] = a[i], post[i] = a[(i + 1) % n];
	for (long i = 0; i < n; i++) dfs(0, i);
	printf("%ld\n", ans);
}