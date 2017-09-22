#include <algorithm>
#include <cstdio>
using namespace std;
long a, b, c,maxnum,minnum;
int main() {
	scanf("%ld%ld%ld", &a, &b, &c);
	maxnum = max(max(a, b), c); minnum=min(min(a, b), c);
	printf("%ld", maxnum - minnum);
}