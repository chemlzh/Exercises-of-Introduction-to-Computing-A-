#include <cstdio>
#include <cstring>
char str[105];
long len;
int main() {
	scanf("%s", str); len = strlen(str);
	for (long i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) { printf("%s", "no"); return 0; }
	}
	printf("%s", "yes");
}