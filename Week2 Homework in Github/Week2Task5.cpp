#include <cstdio>
long n,now,ans,maxpoll,bucket[20];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &now);
		bucket[now]++;
	}
	for(long i=1;i<=15;i++)
		if (bucket[i] > maxpoll) { maxpoll = bucket[i]; ans = i; }
	printf("%ld", ans);
}