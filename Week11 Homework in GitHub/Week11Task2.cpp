#include <algorithm>
#include <cstdio>
using namespace std;
long t, m, n, k, a[25][25];
inline void dfs(long apple,long ma,long plate) {
	if (apple == 0) { k++; return; }
	else if (plate == 0 && apple != 0) return;
	else {
		for (long i = min(ma, apple); i >= 1; i--) dfs(apple - i, i, plate - 1);
	}
}
int main() {
	scanf("%ld", &t);
	for (long i = 1; i <= t; i++) {
		scanf("%ld%ld", &m, &n);
		k = 0, dfs(m, m, n);
		printf("%ld\n", k);
	}
}