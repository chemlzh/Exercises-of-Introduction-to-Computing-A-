#include <cstdio>
#include <stack>
using namespace std;
struct student{ long pos; char c; }s0;
stack<student> s;
char c;
long p;
int main() {
	c = getchar();
	while (c != '\n') {
		if (s.empty() || c == s.top().c) s0.c = c, s0.pos = p, s.push(s0);
		else printf("%ld %ld\n", s.top().pos, p), s.pop();
		p++, c = getchar();
	}
}