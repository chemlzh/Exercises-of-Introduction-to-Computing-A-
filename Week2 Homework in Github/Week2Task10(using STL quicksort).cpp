#include <algorithm>
#include <cstdio>
using namespace std;
long n, k, a[1005];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld", &a[i]);
	scanf("%ld",&k);
	sort(a + 1, a + n + 1);
	for (long i = n; i >= n - k + 1; i--) {
		printf("%ld", a[i]); 
		if (i != n - k + 1) printf("\n");
	}
}