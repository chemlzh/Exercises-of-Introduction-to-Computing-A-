#include <cstdio>
#include <stack>
using namespace std;
struct frac { long p, q; }target;
long n;
stack<frac> s;
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld", &target.p, &target.q);
		while (target.p != target.q) {
			s.push(target);
			if (target.p > target.q) target.p -= target.q;
			else if (target.p < target.q) target.q -= target.p;
		}
		long ans = 1;
		while (!s.empty()) {
			target = s.top(), s.pop();
			if (target.p > target.q) ans = ans * 2 + 1;
			else if (target.p < target.q) ans = ans * 2;
		}
		printf("%ld\n", ans);
	}
}