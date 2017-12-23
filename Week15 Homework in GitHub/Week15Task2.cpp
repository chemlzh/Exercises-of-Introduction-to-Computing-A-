#include <algorithm>
#include <cstdio>
using namespace std;
long num[305], cnt, flag, tmp;
char c;
int main() {
	while ((c = getchar()) != '\n') {
		if (c >= '0'&&c <= '9') tmp = tmp * 10 + c - '0', flag = 1;
		else if (flag) num[++cnt] = tmp, tmp = 0, flag = 0;
	}
	if (flag) num[++cnt] = tmp, tmp = 0, flag = 0;
	if (!cnt) printf("%ld", 0);
	else {
		sort(num + 1, num + cnt + 1);
		for (long i = 1; i <= cnt; i++) {
			printf("%ld", num[i]);
			if (i != cnt) printf("%c", ',');
		}
	}
}