#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
struct element{ bool IsOp; double num; }e[2005];
const long op[5] = { '\0','+','-','*','/' };
char c, str[25];
long len, cnt;
double ans, a, b;
stack<double> s;

inline void init() {
	do {
		c = getchar();
		if (c == ' ' || c == '\n') {
			cnt++;
			if (strlen(str) > 1) e[cnt].IsOp = 0, e[cnt].num = atof(str);
			else {
				for (long i = 1; i <= 4; i++) {
					if (str[0] == op[i]) { e[cnt].IsOp = 1, e[cnt].num = i; break; }
				}
			}
			memset(str, 0, sizeof(str)), len = 0;
		}
		else str[len++] = c;
	} while (c != '\n');
}

inline void work() {
	for (long i = cnt; i >= 1; i--) {
		if (!e[i].IsOp) s.push(e[i].num);
		else {
			a = s.top(), s.pop(), b = s.top(), s.pop();
			if (e[i].num == 1.0) s.push(a + b);
			else if (e[i].num == 2.0) s.push(a - b);
			else if (e[i].num == 3.0) s.push(a*b);
			else if (e[i].num == 4.0) s.push(a / b);
		}
	}
	printf("%f\n", s.top());
}

int main() {
	init();
	work();
}