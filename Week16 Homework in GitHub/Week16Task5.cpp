#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <deque>
using namespace std;
struct token { long flag; double value; }t, t0;
deque <token> num;
stack <double> now;
long cnt;
double ans, t1, t2;
char c, tmp[105];
inline double calc(double op0, double a, double b) {
	if (op0 == 1) return a + b;
	else if (op0 == 2) return a - b;
	else if (op0 == 3) return a * b;
	else if (op0 == 4) return a / b;
}
int main() {
	do {
		c = getchar();
		if (c == '+') t.flag = 1, t.value = 1, num.push_back(t);
		else if (c == '-') t.flag = 1, t.value = 2, num.push_back(t);
		else if (c == '*') t.flag = 1, t.value = 3, num.push_back(t);
		else if (c == '/') t.flag = 1, t.value = 4, num.push_back(t);
		else if (c == '.' || (c >= '0'&&c <= '9')) tmp[cnt++] = c;
		else {
			if (cnt) {
				cnt = 0, t.flag = 0, t.value = atof(tmp);
				num.push_back(t), memset(tmp, '\0', sizeof(tmp));
			}
		}
	} while (c != '\n');
	while (!num.empty()) {
		t0 = num.back(), num.pop_back();
		if (!t0.flag) now.push(t0.value);
		else t1 = now.top(), now.pop(), t2 = now.top(), now.pop(), now.push(calc(t0.value, t1, t2));
	}
	printf("%f\n", now.top()), now.pop();
}