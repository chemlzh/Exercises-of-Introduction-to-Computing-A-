#include <cstdio>			
const long mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
long count[7];					//count[0],count[1], ... ,count[6]分别表示星期六、星期日、...、星期五的次数
long N,tmp;
int main() {
	scanf("%ld", &N); count[0] = 1;
	for (long i = 1900; i <= 1900+N - 1; i++) {
		for (long j = 0; j <= 11; j++) {
			if (i == 1900+N - 1 && j == 11) break;
			if (((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) && j == 1)  tmp = (tmp + mon[j] + 1) % 7;
			else tmp = (tmp + mon[j]) % 7;
			count[tmp]++;
		}
	}
	for (long i = 0; i <= 6; i++) {
		printf("%ld", count[i]);
		if (i != 6) printf(" ");
	}
 }

//This question is the same as "Friday the Thirteenth" in USACO training.