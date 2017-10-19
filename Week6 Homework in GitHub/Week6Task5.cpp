#include <cstdio>
long N, sum, tmp, cnt, maxnum;
int main() {
	scanf("%ld", &N);
	for (long i = 1; i <= N; i++) {
		scanf("%ld", &tmp);
		sum += tmp;
		if (tmp > maxnum) { cnt = 1; maxnum = tmp; }
		else if (tmp == maxnum) cnt++;
	}
	printf("%ld", sum - maxnum*cnt);
}