#include <cstdio>
const long m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
long n, flag;
long year, month, day, hour, minute, second;
int main() {
	while (scanf("%ld", &n) != EOF) {
		second = n % 60, n /= 60;
		minute = n % 60, n /= 60;
		hour = n % 24, n /= 24;
		year = 1970, n++;
		while (n >= 367) {
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) flag = 1;
			else flag = 0;
			n -= 365 + flag, year++;
		}
		if (n == 366) {
			if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) n -= 365, year++;	
		}
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) flag = 1;
		else flag = 0;
		for (long i = 1; i <= 12; i++) {
			if (flag&&i == 2 && n > m[i] + 1) n -= m[i] + 1;
			else if ((!flag || i != 2) && n > m[i]) n -= m[i];
			else { month = i, day = n; break; }
		}
		printf("%ld-%02ld-%02ld %02ld:%02ld:%02ld\n", year, month, day, hour, minute, second);
	}
}