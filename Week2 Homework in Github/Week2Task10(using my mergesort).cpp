#include <cstdio>
#include <cstring>
long n, k, a[1005],t[1005];
inline void mergesort(long left,long right) {
	if (left == right) return;
	if ((left +1 == right)&&(a[left]>a[right])) {
		long temp = a[left]; a[left] = a[right]; a[right] = temp; return;
	}
	long mid = (left + right) / 2, p1 = left, p2 = mid + 1, cnt = 1;
	mergesort(left,mid);
	mergesort(mid+1,right);
	while ((p1<=mid)&&(p2<=right)) {
		if (a[p1] <= a[p2]) t[cnt++] = a[p1++];
		else t[cnt++] = a[p2++];
	}
	while (p1 <= mid) t[cnt++] = a[p1++];
	while (p2 <= right) t[cnt++] = a[p2++];
	for (long i = 1; i <= cnt - 1; i++) a[left + i - 1] = t[i];
	memset(t,0,sizeof(t));
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld", &a[i]);
	scanf("%ld", &k);
	mergesort(1,n);
	for (long i = n; i >= n - k + 1; i--) {
		printf("%ld", a[i]);
		if (i != n - k + 1) printf("\n");
	}
}