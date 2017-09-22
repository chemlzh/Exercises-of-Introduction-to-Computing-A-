#include <cstdio>
long n, k, a[1005];
inline void quicksort(long left, long right) {
	long mid = (left + right) / 2,num=a[mid],temp,l=left,r=right;
	do {
		while (a[l] < num) l++;
		while (a[r] > num) r--;
		if (l <= r) {
			temp = a[l]; a[l] = a[r]; a[r] = temp;
			l++; r--;
		}
	} while (l<=r);
	if (left<r) quicksort(left,r);
	if (l<right) quicksort(l,right);
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld", &a[i]);
	scanf("%ld", &k);
	quicksort(1,n);
	for (long i = n; i >= n - k + 1; i--) {
		printf("%ld", a[i]);
		if (i != n - k + 1) printf("\n");
	}
}