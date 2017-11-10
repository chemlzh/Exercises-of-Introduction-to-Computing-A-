#include <algorithm>
#include <cstdio>
using namespace std;
long n, ans, f[105];
double medicine[105];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) { scanf("%lf", &medicine[i]); f[i] = 1; }
	for (long i = 2; i <= n; i++) {
		for (long j = 1; j <= i - 1; j++) {
			if (medicine[j] >= medicine[i]) f[i] = max(f[i], f[j] + 1);
		}
		ans = max(ans, f[i]);
	}
	printf("%ld", ans);
}