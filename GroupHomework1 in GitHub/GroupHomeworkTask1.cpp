#include <cstdio>
long N, X, Y, K;
long infect[15], sum[15];
int main() {
	scanf("%ld%ld%ld", &N, &X, &Y);
	scanf("%ld", &K);
	sum[1] = N;
	for (long i = 2; i <= K; i++) {
		if (i-Y+2<1) {
			infect[i] += sum[i - 1] * X;
			sum[i] = sum[i - 1] + infect[i];
		}
		else {
			infect[i] += (sum[i - 1] - sum[i - Y + 1])*X;
			sum[i] = sum[i - 1] + infect[i];
		}
	}
	printf("%ld", sum[K] - sum[K - Y + 1]);
}