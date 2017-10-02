#include <cstdio>
long N, M, k, p, line, column, tmp, cnt1, cnt2, maxl, maxc;
long a[105], b[105];
int main() {
	scanf("%ld%ld", &N, &M);
	scanf("%ld", &k);
	for (long i = 1; i <= k; i++) {
		scanf("%ld", &line); 
		if (line - tmp != 1) a[++cnt1] = line - tmp - 1;
		tmp = line;
	}
	if (M-line!=0) a[++cnt1] = M - line; 
	tmp = 0; 
	scanf("%ld", &p);
	for (long i = 1; i <= p; i++) {
		scanf("%ld", &column);
		if (column - tmp != 1) b[++cnt2] = column - tmp - 1;
		tmp = column;
	}
	if (N-column!=0) b[++cnt2] = N - column;	
	for (long i = 1; i <= cnt1; i++) if (a[i] > maxl) maxl = a[i];
	for (long i = 1; i <= cnt2; i++) if (b[i] > maxc) maxc = b[i];
	printf("%ld\n", maxc*maxl);
}