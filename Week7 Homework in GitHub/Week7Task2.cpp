#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1005];
long len;
inline bool cmp(char a, char b) { return a > b; }
int main() {
	do { str[len++] = getchar(); } while (str[len - 1] != '\n');
	str[len] = '\0';  len--;  sort(str, str + len / 2, cmp);
	for (long i = (len + 1) / 2; i <= len - 1; i++) printf("%c", str[i]);
	if (len % 2) printf("%c", str[len / 2]);
	for (long i = 0; i <= len / 2 - 1; i++) printf("%c", str[i]);
}