#include <cstdio>
long k, m, tmp, num[35];
char c;

inline void init() {
	c = getchar();
	while (c != '\n') num[0]++, num[num[0]] = c - '0', c = getchar();
	for (long i = 1; i <= num[0] / 2; i++) {
		tmp = num[i], num[i] = num[num[0] - i + 1], num[num[0] - i + 1] = tmp;
	}
}

inline void work() {
	long p;
	for (long i = 1; i <= m; i++) {
		num[1]++, p = 1;
		while (num[p] >= k) num[p + 1] += num[p] / k, num[p] %= k, p++;
		if (p > num[0]) num[0] = p;
		for (long j = num[0]; j >= 1; j--) printf("%ld", num[j]);
		if (i == m) break;
		else if (i % 5 == 0) printf("\n"); 
		else printf("%c", ',');
	}
}

int main() {
	scanf("%ld,%ld,", &k, &m);
	init(), work();
}