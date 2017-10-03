#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long long f[85][85], tmp;
long n, m, a[85][85];
long long ans;
int main() {
	scanf("%ld%ld", &n, &m);
	for (long i = 1; i <= n; i++)
		for (long j = 1; j <= m; j++) scanf("%ld", &a[i][j]);
	for (long line = 1; line <= n; line++) {											//Work on specific line
		tmp = 0;
		for (long i = 1; i <= m; i++) {													//Choose 'i' colum
			f[i][0] = f[i - 1][0] + i * a[line][i];
			f[0][i] = f[0][i - 1] + i * a[line][m-i+1];
			for (long left = 1; left <= i - 1; left++) {								//Choose 'left' columns from left side
				long right = i - left;
				if (f[left - 1][right] + i * a[line][left] > f[left][right - 1] + i * a[line][m - right + 1]) 
					f[left][right] = f[left - 1][right] + i * a[line][left];
				else f[left][right] = f[left][right - 1] + i * a[line][m - right + 1];
			}
		}
		for (long i = 0; i <= m; i++) if (tmp < f[i][m - i]) tmp = f[i][m - i];
		ans += tmp;
	}
	printf("%lld", ans);
}

//The origin is NOIP 2007 Senior,and it's the same as Vijos P1378.