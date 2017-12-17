#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double ave, delta;
long l[305], ans[305], n;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld", &l[i]), ave += l[i];
	ave /= n;
	for (long i = 1; i <= n; i++) {
		if (abs(l[i] - ave) > delta) {
			memset(ans, 0, sizeof(ans));
			ans[0] = 1, ans[1] = l[i], delta = abs(l[i] - ave);
		}
		else if (abs(l[i] - ave) == delta) ans[++ans[0]] = l[i];
	}
	sort(ans + 1, ans + ans[0] + 1);
	printf("%ld", ans[1]);
	for (long i = 2; i <= ans[0]; i++) printf(",%ld", ans[i]);
}