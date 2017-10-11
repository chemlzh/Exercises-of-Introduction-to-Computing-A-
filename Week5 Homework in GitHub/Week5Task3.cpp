#include <cstdio>
long n;
int main() {
	while (scanf("%ld", &n) != EOF) {
		if (n % 3 == 0) printf("%s\n", "TRUE");
		else {
			while (n) {
				if (n % 10 == 3) { printf("%s\n", "TRUE"); break;  }
				else n /= 10;
			}
			if (!n)  printf("%s\n", "FALSE");
		}
	}
}