#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
long cnt;
char c, t[1005];
stack <char> op;
stack <long> num;
inline long pr(char op0) {
	if (op0 == '!') return 2;
	else if (op0 == '&' || op0 == '|') return 1;
	else if (op0 == '(' || op0 == ')') return 0;
}
inline void calc(char op0) {
	long tmp1, tmp2;
	if (op0 == '!') {
		tmp1 = num.top(), num.pop(), num.push(!tmp1);
	}
	else if (op0 == '|') {
		tmp1 = num.top(), num.pop(), tmp2 = num.top(), num.pop(), num.push(tmp1 || tmp2);
	}
	else if (op0 == '&') {
		tmp1 = num.top(), num.pop(), tmp2 = num.top(), num.pop(), num.push(tmp1&&tmp2);
	}
}
int main() {
	while ((c = getchar()) != EOF) {
		if (c == ' ') continue;
		else if (c == '\n') {
			for (long i = 0; i < cnt; i++) {
				if (t[i] == 'V') num.push(1);
				else if (t[i] == 'F') num.push(0);
				else if (t[i] == '(') op.push(t[i]);
				else if (t[i] == ')') {
					while (op.top() != '(') calc(op.top()), op.pop();
					op.pop();
				}
				else {
					if (op.empty() || num.empty()) op.push(t[i]);
					else if (pr(op.top()) < pr(t[i])) op.push(t[i]);
					else {
						while (pr(op.top()) >= pr(t[i])) {
							calc(op.top()), op.pop();
							if (op.empty()) break;
						}
						op.push(t[i]);
					}
				}
			}
			while (!op.empty()) calc(op.top()), op.pop();
			if (num.top()) printf("%c\n", 'V'); else printf("%c\n", 'F');
			num.pop(), memset(t, '\0', sizeof(t)), cnt = 0;
		}
		else if (c == '!'&&t[cnt - 1] == '!') cnt--, t[cnt] = '\0';
		else t[cnt++] = c;
	}
}