#include <cstdio>
const long prime[7] = {1,2,3,5,7,11};
long m, n, cnt, cnt1, tmp[10005], delta;
inline long long Pow_mod(long long a,long long b,long long n) {
	if (!b) return 1;
	long long ans = Pow_mod(a, b / 2, n);
	ans = (ans*ans) % n;
	if (b % 2) ans = (ans*a) % n;
	return ans;
}
inline bool IsPrime(long long num) {
	long long d = num - 1, s = 0;
	bool flag = true;
	if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0 || num % 11 == 0) {
		if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11) return true; else return false;
	}
	while (d>1 && d % 2 ==0) d /= 2;
	for (long i = 1; i <= 5; i++) {
		bool flag1 = false;
		long long dd = d, tmp = Pow_mod(prime[i], dd, num);
		while (dd != num - 1 && tmp != 1 && tmp != num - 1) {
			tmp = (tmp*tmp) % num; dd *= 2;
		}
		if (tmp == num - 1 || dd % 2 != 0) flag1 = true;
		flag = flag&&flag1;
	}
	return flag;
}
int main() {
	scanf("%ld,%ld", &m, &n);
	for (long i = m; i <= n; i++) {
		if (i == 1) continue;
		if (IsPrime(i)) tmp[++cnt] = i;
	}
	for (long i = 1; i <= cnt; i++) {
		for (long j = i + 1; j <= cnt; j++) {
			delta = tmp[j] - tmp[i]; 
			if (IsPrime(delta)) { printf("(%ld,%ld)\n", tmp[i], tmp[j]); cnt1++; }
		}
	}
	if (!cnt1) printf("%s\n", "NULL");
}