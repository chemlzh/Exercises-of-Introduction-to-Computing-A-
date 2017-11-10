#include <cstdio>
#include <cstring>
struct patient { long num, status; }p[1005];
long t, n, k, ans;
inline void insert(long cnt,patient pp) {
	long pos = cnt - 1;
	patient tmp = pp;
	while (pos > 0 && p[pos].status < tmp.status) p[pos + 1] = p[pos], pos--;
	p[pos+1] = tmp;
}
inline long min(long num1, long num2) {
	if (num1 <= num2) return num1;
	return num2;
}
int main() {
	scanf("%ld", &t);
	for (long i = 1; i <= t; i++) {
		scanf("%ld%ld", &n, &k);
		for (long j = 1; j <= n; j++) { scanf("%ld", &p[j].status); p[j].num = j; }
		ans = min(n, k), printf("%ld\n", ans);
		for (long j = 1; j <= n; j++) insert(j, p[j]);
		for (long j = 1; j <= ans - 1; j++) printf("%ld ", p[j].num); 
		printf("%ld\n", p[ans].num);
	}
}