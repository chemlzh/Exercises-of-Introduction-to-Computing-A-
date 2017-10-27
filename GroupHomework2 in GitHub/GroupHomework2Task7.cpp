#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct pos { long l, r, dis; }tmp[1005],p[1005];
char func[2010];
long cnt,delta;
inline bool cmp(pos p1,pos p2) {
	if (p1.dis < p2.dis) return true;
	else if (p1.dis > p2.dis) return false;
	else if (p1.l < p2.r) return true;
	else return false;
}
int main() {
	scanf("%s", func);
	for (long i = 0; i < strlen(func); i++) {
		if (func[i] == ')') {
			if (delta <= 0) { printf("%s", "mismatch"); return 0; }
			else { 
				cnt++; 
				p[cnt].l = tmp[delta].l; p[cnt].r = i + 1; p[cnt].dis = p[cnt].r - p[cnt].l;
				delta--;
			}
		}
		if (func[i]=='(') {
			delta++; tmp[delta].l = i+1;
		}
	}
	if (delta) printf("%s", "mismatch");
	else if (cnt) {
		sort(p + 1, p + cnt + 1, cmp);
		for (long i = 1; i <= cnt; i++) printf("%ld,%ld\n", p[i].l, p[i].r);
	}
	else { printf("%ld,%ld\n", 0L, 0L); }
}