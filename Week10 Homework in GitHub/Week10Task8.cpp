#include <cstdio>
#include <stack>
using namespace std;
struct student { long p; char c; }tmp;
stack<student> s;
long pos;
char c;
int main() {
	c = getchar();
	while (c != '\n') {
		if (s.empty() || c == s.top().c) tmp.c = c, tmp.p = pos, s.push(tmp);
		else printf("%ld %ld\n", s.top().p, pos), s.pop();
		pos++, c = getchar();
	}
}

//这道题的输入是两种字符，让你配对，可不仅只有左右括号这种情况！
//看来我是星际玩家，题目都没看清楚……