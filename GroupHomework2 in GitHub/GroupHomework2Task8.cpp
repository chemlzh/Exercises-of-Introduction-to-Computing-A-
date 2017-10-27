#include <cstdio>
long y, m, d = 1L;
long month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	scanf("%ld%ld", &y, &m);
	printf("%s\n", " Sun Mon Tue Wed Thu Fri Sat");
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) month[2]++;
	for (long i = 1901; i < y; i++) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) d = (d + 2) % 7; else d = (d + 1) % 7;
	}
	for (long i = 1; i < m; i++) d = (d + month[i]) % 7;
	for (long j = 1; j <= (d + 1) % 7; j++) printf("    ");
	for (long i = 1; i <= month[m]; i++) {
		if (i / 10) printf("  "); else printf("   ");
		printf("%ld", i);
		if ((i + d) % 7 == 6) printf("\n");
	}
}