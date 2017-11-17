#include <cstdio>
long m, n, tmp;
inline void PrintResult(long sign) {
	if (sign) printf("%s\n", "win"); else printf("%s\n", "lose");
}
int main() {
	for (;;) {
		scanf("%ld%ld", &m, &n);
		if (m == 0 && n == 0) break;
		else {
			long flag = 1;
			for (;;) {
				if (m < n) tmp = m, m = n, n = tmp;
				else if (m == n) { PrintResult(flag); break; }
				else {
					if (m / n >= 2) { PrintResult(flag); break; }
					else tmp = m - n, m = n, n = tmp, flag = !flag;
				}
			}
		}
	}
}

//This question is similar to Vijos 1208.