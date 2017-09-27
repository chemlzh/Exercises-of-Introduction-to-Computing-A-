#include <cstdio>
#include <cmath>
long m, k,cnt;
int main() {
	scanf("%ld%ld", &m, &k);
	for (long i = m+1; cnt < k; i++) {
		bool flag = true;
		for (long j = 2; j <= ceil(sqrt(i)); j++) 
			if (i%j == 0) flag = false;
		if (flag) { 
			cnt++; printf("%ld", i); 
			if (cnt != k) printf(" ");
		}
	}
}