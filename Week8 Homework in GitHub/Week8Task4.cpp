#include <cstdio>
long m[25][25];
long n, x, y;
int main() {
	scanf("%ld", &n);
	x = 1, y = n / 2 + 1, m[x][y] = 1;
	for (long i = 2; i <= n*n; i++) {
		if (x == 1 && y != n) { x = n; y++; }
		else if (x != 1 && y == n) { x--; y = 1; }
		else if (x == 1 && y == n) x++; 
		else if (m[x - 1][y + 1]) x++;
		else { x--; y++; }
		m[x][y] = i;
	}
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) {
			printf("%ld", m[i][j]);
			if (j != n) printf(" ");
		}
		printf("\n");
	}
}