#include <cstdio>
long n,now,maxnum=0,cnt=0,ans=0;
inline long cmp(long a,long b) {
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}
int main() {
	scanf("%ld",&n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &now);
		ans += now;
		if (cmp(now, maxnum) == 1) {
			maxnum = now;  cnt = 1;
		}
		else if (cmp(now, maxnum) == 0)  cnt++;
	}
	ans -= maxnum*cnt;
	printf("%ld", ans);
}