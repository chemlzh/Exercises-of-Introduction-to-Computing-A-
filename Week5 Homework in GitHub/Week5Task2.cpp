#include <cstdio>
long a[15], b[15], c[30];
void MergeSort() {
	long p1 = 1, p2 = 1, p = 0;
	while (p1 <= 10 && p2 <= 10) {
		if (a[p1] <= b[p2]) c[++p] = a[p1++];  else c[++p] = b[p2++]; 
	}
	while (p1 <= 10) c[++p] = a[p1++]; 
	while (p2 <= 10) c[++p] = b[p2++];
}
int main() {
	for (long i = 1; i <= 10; i++) scanf("%ld", &a[i]);
	for (long i = 1; i <= 10; i++) scanf("%ld", &b[i]);
	MergeSort();
	for (long i = 1; i <= 20; i++) { printf("%ld", c[i]); if (i != 20) printf(" "); }
}