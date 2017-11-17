#include <cstdio>
#include <cstring>
long flag = 1;
char num[15];
int main() {
	scanf("%s", num);
	for (long i = 0; i <= (strlen(num) - 1) / 2; i++) {
		if (num[i] != num[strlen(num) - i - 1]) { flag = 0; break; }
	}
	if (flag) printf("%s", "yes"); else printf("%s", "no");
}