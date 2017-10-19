#include <cstdio>
long H, U, D, ans, tmp;
int main() {
	scanf("%ld%ld%ld", &H, &U, &D);
	tmp = U; ans = 1;
	while (tmp<H) {
		ans++; tmp += U - D;
	}
	printf("%ld", ans);
}