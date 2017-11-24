#include <cctype>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
struct token { long num; bool op; }t[10005];
char str[10005];
long ans, cnt;
stack<long> OpS, NumS;
inline void init() {
	memset(t, 0, sizeof(t)), cnt = 0;
	for (long i = 0; i < strlen(str); i++) {
		cnt++;
		if (isdigit(str[i])) {
			t[cnt].num = t[cnt].num * 10 + str[i] - '0';
			while (isdigit(str[i + 1])) t[cnt].num = t[cnt].num * 10 + str[i + 1] - '0', i++;
		}
		else if (str[i] == '+') {
			if ((i > 0 && str[i - 1] == ')') || (str[i - 1] >= '0'&&str[i - 1] <= '9'))
				t[cnt].num = 3, t[cnt].op = 1;
			else t[cnt].num = 7, t[cnt].op = 1;
		}
		else if (str[i] == '-') {
			if ((i > 0 && str[i - 1] == ')') || (str[i - 1] >= '0'&&str[i - 1] <= '9'))
				t[cnt].num = 4, t[cnt].op = 1;
			else t[cnt].num = 8, t[cnt].op = 1;
		}
		else if (str[i] == '*') t[cnt].num = 5, t[cnt].op = 1;
		else if (str[i] == '/') t[cnt].num = 6, t[cnt].op = 1;
		else if (str[i] == '(') t[cnt].num = 1, t[cnt].op = 1;
		else if (str[i] == ')') t[cnt].num = 2, t[cnt].op = 1;
	}
}
inline void calc(long op0) {
	long tmp1, tmp2;
	switch (op0) {
	case 3: {
		tmp1 = NumS.top(), NumS.pop(), tmp2 = NumS.top(), NumS.pop(), NumS.push(tmp1 + tmp2);
		break;
	}
	case 4: {
		tmp1 = NumS.top(), NumS.pop(), tmp2 = NumS.top(), NumS.pop(), NumS.push(tmp2 - tmp1);
		break;
	}
	case 5: {
		tmp1 = NumS.top(), NumS.pop(), tmp2 = NumS.top(), NumS.pop(), NumS.push(tmp1*tmp2);
		break;
	}
	case 6: {
		tmp1 = NumS.top(), NumS.pop(), tmp2 = NumS.top(), NumS.pop(), NumS.push(tmp2 / tmp1);
		break;
	}
	case 7: {
		tmp1 = NumS.top(), NumS.pop(), NumS.push(tmp1); break;
	}
	case 8: {
		tmp1 = NumS.top(), NumS.pop(), NumS.push(-tmp1); break;
	}
	}
}
inline long work() {
	for (long i = 1; i <= cnt; i++) {
		if (t[i].op) {
			if (t[i].num >= 3) {
				if (OpS.empty()) OpS.push(t[i].num);
				else {
					if ((OpS.top() + 1) / 2 < (t[i].num + 1) / 2) OpS.push(t[i].num);
					else {
						while ((OpS.top() + 1) / 2 >= (t[i].num + 1) / 2) {
							calc(OpS.top()), OpS.pop();
							if (OpS.empty()) break;
						}
						OpS.push(t[i].num);
					}
				}
			}
			else if (t[i].num == 1) OpS.push(t[i].num);
			else if (t[i].num == 2) {
				while (OpS.top()!=1) calc(OpS.top()), OpS.pop();
				OpS.pop();
			}
		}
		else NumS.push(t[i].num);
	}
	while (!OpS.empty()) calc(OpS.top()), OpS.pop();
	ans = NumS.top(), NumS.pop();
	return ans;
}
int main() {
	while (scanf("%s", str) != EOF) {
		init(), printf("%ld\n", work());
	}
}