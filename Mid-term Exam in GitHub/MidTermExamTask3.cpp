#include <cstdio>
long n, tmp, bucket[105];
int main(){
	scanf("%ld",&n);
	for (long i = 1; i <= n; i++) { scanf("%ld", &tmp); bucket[tmp]++; }
	for (long i = 1; i <= n; i++) { if (!bucket[i]) printf("%ld\n", i); }
}