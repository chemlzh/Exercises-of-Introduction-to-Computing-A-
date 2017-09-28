#include <cstdio>
long n, m, k, a[46][225];
int main() {
	scanf("%ld,%ld,%ld", &n, &m, &k);
	for (long i = n+1; i < m; i++) {
		long num=i, tmp=0;
		while (num != 0) { tmp += num % 10; num /= 10; }
		if (tmp%k == 0) { a[tmp][0]++; a[tmp][a[tmp][0]] = i; }
	}
	for (long i = 1; i <= 45 / k; i++) {
		if (a[i*k][0]) {
			for (long j = 1; j <= a[i*k][0]; j++) { 
				printf("%ld", a[i*k][j]); 
				if (j != a[i*k][0]) printf("%c", ',');
			}
			if (i != 45 / k) printf("\n");
		}
	}
}