#include <cstdio>
long a, b, aw, bw, n;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &a, &b);
		if ((a == 0) && (b == 1)) aw++;
		else if ((a == 0) && (b == 2)) bw++;
		else if ((a == 1) && (b == 0)) bw++;
		else if ((a == 1) && (b == 2)) aw++;
		else if ((a == 2) && (b == 0)) aw++;
		else if ((a == 2) && (b == 1)) bw++;
	}
	if (aw > bw) printf("%c", 'A');
	else if (aw < bw) printf("%c", 'B');
	else printf("%s", "Tie");
}