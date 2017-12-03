#include <cstdio>
const long pow10[8] = { 1,10,100,1000,10000,100000,1000000,10000000 };
long n, b, cnt, a0[9], a1[9], a2[16], a3[16], ans[93];
inline void calc(long step) {
	if (step > 8) {
		cnt++;
		for (long i = 1; i <= 8; i++) ans[cnt] += pow10[8 - i] * a0[i];
	}
	else {
		for (long i = 1; i <= 8; i++) {
			if (a1[i] == 0 && a2[step + i - 1] == 0 && a3[step - i + 8] == 0) {
				a0[step] = i, a1[i] = a2[step + i - 1] = a3[step - i + 8] = 1;
				calc(step + 1);
				a0[step] = a1[i] = a2[step + i - 1] = a3[step - i + 8] = 0;
			}
		}
	}
}
int main() {
	scanf("%ld", &n);
	calc(1);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &b), printf("%ld\n", ans[b]);
	}
}