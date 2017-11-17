#include <cstdio>
#include <cstring>
const char HaabMonthName[19][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin" ,
											"mol", "chen", "yax", "zac", "ceh", "mac", "kankin",
											"muan", "pax", "koyab", "cumhu","uayet" },
	TzolkinDayName[20][10] = { "imix", "ik", "akbal", "kan", "chicchan",
											   "cimi", "manik", "lamat", "muluk", "ok",
											   "chuen", "eb", "ben", "ix", "mem",
											   "cib","caban", "eznab", "canac", "ahau" };
const long Haab[19] = { 20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,5 };
const long HaabSum[19] = { 20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,365 };
long n, HaabYear, HaabMonth, HaabDay, TzolkinDay, TzolkinPeriod, TzolkinYear;
char c;
inline void Init() {
	long flag = 0, len = 0;
	char month[10], c = getchar();
	memset(month, '\0', sizeof(month));
	HaabDay = HaabMonth = HaabYear = 0;
	TzolkinDay = TzolkinPeriod = TzolkinYear = 0;
	while (c != '\n') {
		if (c >= '0'&&c <= '9') {
			if (flag) HaabYear = HaabYear * 10 + c - '0';
			else HaabDay = HaabDay * 10 + c - '0';
		}
		else if (c >= 'a'&&c <= 'z') month[len++] = c, flag = 1;
		c = getchar();
	}
	for (long i = 0; i < 19; i++) {
		if (strcmp(HaabMonthName[i], month) == 0) { HaabMonth = i; break; }
	}
}

inline void Work() {
	long DaySum = HaabYear * 365 + HaabSum[HaabMonth - 1] + HaabDay + 1;
	TzolkinYear = (DaySum - 1) / 260;
	TzolkinPeriod = (DaySum - 1) % 13 + 1;
	TzolkinDay = (DaySum - 1) % 20;
	printf("%ld %s %ld\n", TzolkinPeriod, TzolkinDayName[TzolkinDay], TzolkinYear);
}

int main() {
	scanf("%ld%c", &n, &c), printf("%ld\n", n);
	for (long i = 1; i <= n; i++) {
		Init(), Work();
	}
}