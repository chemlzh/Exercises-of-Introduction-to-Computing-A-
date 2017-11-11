#include <algorithm>
#include <cstdio>
using namespace std;
struct bacteria{ long num;  double rep; }b[105];
long n;
double s, e;
inline bool cmp(bacteria b1,bacteria b2) {
	if (b1.rep < b2.rep) return true;
	if (b1.rep > b2.rep) return false;
	if (b1.num < b2.num) return true;
	return false;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%lf%lf", &b[i].num, &s, &e);
		b[i].rep = (e - s) / s;
	}
	sort(b + 1, b + n + 1, cmp);
	long pos;
	for (pos = 1; pos <= n - 1; pos++) {
		if (b[pos + 1].rep - b[pos].rep > b[n].rep - b[pos + 1].rep
			&&b[pos + 1].rep - b[pos].rep > b[pos].rep - b[1].rep) {
			printf("%ld\n", n - pos);
			for (long i = pos + 1; i <= n; i++) printf("%ld\n", b[i].num);
			printf("%ld\n", pos);
			for (long i = 1; i <= pos; i++) printf("%ld\n", b[i].num);
			break;
		}
	}
}