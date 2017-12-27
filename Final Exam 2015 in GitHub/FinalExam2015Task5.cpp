#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long n, len1, len2, ans, f[505][505];
char s1[505], s2[505];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%s%s", s1, s2), len1 = strlen(s1), len2 = strlen(s2), ans = 0;
		for (long j = 1; j <= len1; j++) {
			for (long k = 1; k <= len2; k++) {
				if (s1[j - 1] == s2[k - 1]) f[j][k] = f[j - 1][k - 1] + 1;
				else f[j][k] = 0;
				ans = max(ans, f[j][k]);
			}
		}
		printf("%ld\n", ans);
	}
}