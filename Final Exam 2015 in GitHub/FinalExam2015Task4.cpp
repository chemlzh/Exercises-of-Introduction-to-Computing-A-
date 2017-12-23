#include <cstdio>
const long month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
long n, y, m, w, d;
char str[20];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld-%ld-%ld %s", &y, &m, &d, str);
		w = (y - 2000) + (y - 1997) / 4 - (y - 2001) / 100 + (y - 2001) / 400, w %= 7;
		for (long j = 0; j < m - 1; j++) w += month[j];
		if ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && m >= 3) w += 1;
		w = (w + 5 + d) % 7;
		if (w == 0 || w == 6) printf("%s\n", "no");
		else if (w == 1 && (str[5] == '1' || str[5] == '6')) printf("%s\n", "yes");
		else if (w == 2 && (str[5] == '2' || str[5] == '7')) printf("%s\n", "yes");
		else if (w == 3 && (str[5] == '3' || str[5] == '8')) printf("%s\n", "yes");
		else if (w == 4 && (str[5] == '4' || str[5] == '9')) printf("%s\n", "yes");
		else if (w == 5 && (str[5] == '5' || str[5] == '0')) printf("%s\n", "yes");
		else if (w == 5 && (str[5]<'0' || str[5]>'9')) printf("%s\n", "yes");
		else printf("%s\n", "no");
	}
}