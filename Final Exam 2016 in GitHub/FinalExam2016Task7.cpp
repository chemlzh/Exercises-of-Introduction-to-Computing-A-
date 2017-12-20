#include <cstdio>
#include <stack>
using namespace std;
stack<char> op;
stack <long> num;
char c, t[1005];
long cnt;
inline long prior(char op0) {
	if (op0 == '!') return 2;
	else if (op0 == '&' || op0 == '|') return 1;
	else if (op0 == '(' || op0 == ')') return 0;
}
inline void calc(char op0) {
	long num1, num2;
	if (op0 == '!') {
		num1 = num.top(), num.pop(), num.push(!num1);
	}
	else if (op0 == '&') {
		num1 = num.top(), num.pop(), num2 = num.top(), num.pop(), num.push(num1 && num2);
	}
	else if (op0 == '|') {
		num1 = num.top(), num.pop(), num2 = num.top(), num.pop(), num.push(num1 || num2);
	}
}
int main() {
	while ((c = getchar()) != EOF) {
		if (c == ' ') continue;
		else if (c == '\n') {
			for (long i = 0; i < cnt; i++) {
				if (t[i] == 'V') num.push(1);
				else if (t[i] == 'F') num.push(0);
				else if (t[i] == '(') op.push('(');
				else if (t[i] == ')') {
					while (op.top() != '(') calc(op.top()), op.pop();
					op.pop();
				}
				else {
					if (op.empty() || num.empty()) op.push(t[i]);
					else if (prior(op.top()) < prior(t[i])) op.push(t[i]);
					else {
						while (prior(op.top()) >= prior(t[i])) {
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