#include <algorithm>
#include <cstdio>
using namespace std;
bool NotPrime[200001];
long tmp[10000], m, n, cnt, cnt1;
int main() {
	scanf("%ld,%ld", &m, &n); 
	NotPrime[0] = NotPrime[1] = true;
	for (long i = 2; i <= 447; i++) {
		if (NotPrime[i]) continue;
		for (long j = 2 * i; j <= 200001; j += i) NotPrime[j] = true;
	}
	for (long i = m; i <= n; i++) if (!NotPrime[i]) { tmp[++cnt] = i; }
	for (long i = 1; i <= cnt; i++) {
		for (long j = i + 1; j <= cnt; j++) {
			if (!NotPrime[tmp[j] - tmp[i]]) { printf("(%ld,%ld)\n", tmp[i], tmp[j]); cnt1++; }
		}
	}
	if (!cnt1) printf("%s\n", "NULL");
}