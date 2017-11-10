#include <cstdio>
long n, tmp, ans;
inline bool check(long num) {
	if (num % 4 == 0) return false;
	long t = num;
	while (t > 0) {
		if (t % 10 == 4) return false;
		t /= 10;
	}
	return true;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		do { tmp++; } while (!check(tmp));
		ans += tmp;
	}
	printf("%ld", ans);
}