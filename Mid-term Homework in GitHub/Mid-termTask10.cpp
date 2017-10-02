#include <cstdio>
const long stdmon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
long year, month, day, ans;
int main() {
	scanf("%ld%ld%ld", &year, &month, &day);
	for (long i = 1; i < month; i++) ans += stdmon[i];
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		if (month >= 3) ans += day + 1; else ans += day;
	}
	else ans += day;
	printf("%ld", ans);
}