#include <cstdio>
const long kind = 6;
const long money[kind] = { 100,50,20,10,5,1 };
long m;
int main() {
	scanf("%ld", &m);
	for (long i = 0; i < kind; i++) {
		printf("%ld", m/money[i]);
		if (i != kind - 1) printf("\n");
		m %= money[i];
	}
}