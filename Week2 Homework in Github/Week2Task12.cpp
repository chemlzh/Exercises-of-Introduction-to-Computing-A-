#include <cstdio>
long m,a[25],ans,time;
int main() {
	scanf("%ld", &m);
	for (long i = 1; i <= m; i++) {
		scanf("%ld", &a[i]);
		if (time + a[i] - a[i - 1] + 3 <= 60) {
			time += a[i] - a[i - 1] + 3;
			ans += a[i] - a[i - 1];
		}
		else if ((time + a[i] - a[i - 1] + 3 > 60) && (time + a[i] - a[i - 1] <= 60)) {
			time = 60;
			ans += a[i] - a[i - 1];
		}
		else if (time + a[i] - a[i - 1] > 60) {
			ans += 60 - time;
			time = 60;
		}
	}
	ans += 60 - time;
	printf("%ld", ans);
}