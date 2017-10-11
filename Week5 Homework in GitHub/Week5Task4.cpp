#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long n, a[105], b[105], c[210];
char tmp[105];
void init(char num[],long bi[]) {
	bi[0] = strlen(num);
	for (long i = bi[0] - 1; i >= 0; i--) bi[bi[0] - i] = num[i] - '0';
}
void add(long num1[], long num2[],long num3[]) {
	num3[0] = max(num1[0], num2[0]) + 1;
	for (long i = 1; i <= num3[0]; i++) {
		num3[i] += num1[i] + num2[i];
		num3[i + 1] += num3[i] / 2;
		num3[i] %= 2;
	}
	while (!num3[num3[0]]) num3[0]--;
}
void print(long num[]) {
	for (long i = num[0]; i >= 1; i--) printf("%ld", num[i]);
	printf("\n");
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b)); memset(c, 0, sizeof(c));
		scanf("%s", &tmp);	init(tmp,a);
		scanf("%s", &tmp);	init(tmp,b);
		init("0", c);
		add(a, b, c);
		print(c);
	}
}