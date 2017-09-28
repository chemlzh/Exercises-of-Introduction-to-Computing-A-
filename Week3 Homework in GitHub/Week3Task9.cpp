#include <cstdio>
long n,cnt,p,flag[105];
inline bool check(const long num) {
	if (num % 7 == 0) return true;
	long temp = num;
	while (temp != 0) {
		if (temp % 10 == 7) return true; else temp /= 10; 
	}
	return false;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1;; i++) {
		do {
			p = p%n + 1;
		} while (flag[p]);
		if (check(i)) {
			printf("%ld", p);
			flag[p] = 1; cnt++;
			if (cnt != n) printf("\n"); else break;
		}
	}
}