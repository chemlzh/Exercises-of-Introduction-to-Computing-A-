#include <algorithm>
#include <cstdio>
using namespace std;
long n, demand[10005], dis[10005], dissum[10005];
long now, factory, ans = 0x7FFFFFFF;
int main() {
	scanf("%ld", &n);
	for (long i = 0; i < n; i++) {
		scanf("%ld%ld", &demand[i], &dis[i]);
		dissum[i + 1] = dissum[i] + dis[i];
	}
	for (long i = 0; i < n; i++) {
		now = 0;
		for (long j = (i + 1) % n; j != i; j = (j + 1) % n) {
			if (j > i) now += demand[j] * min(dissum[j]-dissum[i], dissum[n] - dissum[j] + dissum[i]);
			else now += demand[j] * min(dissum[i] - dissum[j], dissum[n] - dissum[i] + dissum[j]);
		}
		if (ans > now) ans = now, factory = i;
	}
	printf("%ld,%ld", factory, ans);
}