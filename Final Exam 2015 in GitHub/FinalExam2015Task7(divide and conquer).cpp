#include <algorithm>
#include <cstdio>
using namespace std;
long n, ans, a[50];
char op[50];
inline long devide(long left, long right) {
	if (left == right) return a[left];
	long tmp = 0;
	for (long i = left; i < right; i++) {
		if (op[i] == '+') tmp = max(tmp, devide(left, i) + devide(i + 1, right));
		else tmp = max(tmp, devide(left, i) * devide(i + 1, right));
	}
	return tmp;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld %c", &a[i], &op[i]), a[n + i] = a[i], op[n + i] = op[i];
	for (long i = 1; i <= n; i++) ans = max(ans, devide(i, i + n - 1));
	printf("%ld\n", ans);
}