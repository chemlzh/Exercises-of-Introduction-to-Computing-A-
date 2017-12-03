#include <cstdio>
#include <stack>
using namespace std;
struct child { char c; long pos; }tmp;
stack <child> s;
long pos;
char c;
int main() {
	c = getchar();
	while (c != '\n') {
		tmp.pos = pos, tmp.c = c, pos++;
		if (s.empty() || s.top().c == tmp.c) s.push(tmp);
		else printf("%ld %ld\n", s.top().pos, tmp.pos), s.pop();
		c = getchar();
	}
}