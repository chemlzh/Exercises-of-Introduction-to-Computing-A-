#include <cstdio>
long a;
int main() {
	scanf("%ld", &a);
	if ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0)) printf("%s", "Y");
	else printf("%s", "N");
}