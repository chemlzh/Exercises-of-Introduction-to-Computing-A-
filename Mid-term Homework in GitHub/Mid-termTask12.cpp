#include <algorithm>
#include <cstdio>
using namespace std;
long n;
double t[1005],sum;
int main() {
	while (scanf("%ld", &n) != EOF) {
		for (long i = 1; i <= n; i++) scanf("%lf", &t[i]);
		sort(t + 1, t + n + 1); 
		sum = 0;
		for (long i = 1; i <= n - 1; i++) sum += t[i];
		if (sum >= t[n]) printf("%.1f\n", (sum+t[n]) / 2); else printf("%.1f\n", sum);
	}
}