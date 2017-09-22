#include <cstdio>
long num,cnt=0,a[3];
int main() {
	scanf("%ld", &num);
	if (num % 3 == 0) { a[cnt] = 3;  cnt++; }
	if (num % 5 == 0) { a[cnt] = 5;  cnt++; }
	if (num % 7 == 0) { a[cnt] = 7;  cnt++; }
	if (!cnt) printf("%c", 'n');
	else {
		for (long i = 0; i < cnt - 1; i++) printf("%ld ", a[i]);
		printf("%ld", a[cnt - 1]);
	}
}