#include <cstdio>
long n,number,count;
int main() {
	scanf("%ld",&n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &number);
		long a1 = 0, a2 = number%10; 
		number /= 10;
		while (number  != 0) {
			a1 += number % 10; 
			number /= 10;
		}
		if (a2 > a1) count++;
	}
	printf("%ld", count);
}