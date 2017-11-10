#include <cstdio>
long n;
int main() {
	scanf("%ld", &n);
	if (n == 1 || n == 3 || n == 5) printf("%s", "NO"); else printf("%s", "YES");
}