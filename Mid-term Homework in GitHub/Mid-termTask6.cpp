#include <algorithm>
#include <cstdio>
using namespace std;
long n, demand[10005], dis[10005], dis1[10005];
long dissum, now, ans, mindis = 2147483647;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &demand[i-1], &dis[i]);
		dissum += dis[i]; dis1[i] = dis1[i-1] + dis[i];
	}
	for (long i = 0; i <= n - 1; i++) {
		now = 0;
		for (long j = i + 1; j != i; j = (j + 1) % n) {
			now += min(abs(dis1[j] - dis1[i]), dissum - abs(dis1[j] - dis1[i]))*demand[j];
		}
		if (mindis > now) { ans = i; mindis = now; }
	}
	printf("%ld,%ld", ans, mindis);
}

//提示：运用前缀和可以将整个算法时间复杂度降至O(n^2)