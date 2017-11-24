#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 10005;

int len;
stack<int> num;
stack<int> opt;
char str[maxn];

inline int getid(char ch) {
	if(ch == '(') return 0;
	if(ch == '+') return 2;
	if(ch == '-') return 3;
	if(ch == '*') return 4;
	if(ch == '/') return 5;
	if(ch == '@') return 6;
}

inline int calc(int x, int y, int id) {
	if(id == 2) return x + y;
	if(id == 3) return x - y;
	if(id == 4) return x * y;
	if(id == 5) return x / y;
}

inline void update() {
	if(opt.top() == getid('@')) {
		int x = num.top(); num.pop();
		num.push(-x);
		opt.pop();
	} else {
		int x = num.top(); num.pop();
		int y = num.top(); num.pop();
		int res = calc(y, x, opt.top());
		num.push(res);
		opt.pop();
	}
}

inline bool isNum(int pos) {
	if(pos == 0) return 1;
	if(str[pos - 1] == '(') return 1;
	return 0;
}

inline int solve() {
	for(int i = 0; i < len; ) {
		if(str[i] >= '0' && str[i] <= '9') {
			int x = 0;
			for(; str[i] >= '0' && str[i] <= '9'; i++) x = x * 10 + (str[i] - '0');
			num.push(x);
		}
		else if(str[i] == '-' && isNum(i)) {
			opt.push(getid('@'));
			i++;
		}
		else if(str[i] == '+' && isNum(i)) {
			i++;
		}
		else if(str[i] == '+' || str[i] == '-') {
			int id = getid(str[i]);
			while(!opt.empty() && opt.top() / 2 >= id / 2) update();
			opt.push(getid(str[i]));
			i++;
		}
		else if(str[i] == '*' || str[i] == '/') {
			int id = getid(str[i]);
			while(!opt.empty() && opt.top() / 2 >= id / 2) update();
			opt.push(id);
			i++;
		}
		else if(str[i] == '(') {
			opt.push(0);
			i++;
		}
		else if(str[i] == ')') {
			while(!opt.empty() && opt.top() != 0) update();
			opt.pop();
			i++;
		}
	}
	while(!opt.empty())
		if(opt.top() == 0) opt.pop();
		else update();
	int ans = num.top(); num.pop();
	return ans;
}

int main() {
	while(scanf("%s", str) != EOF) {
		len = strlen(str);
		printf("%d\n", solve());
	}
	return 0;
}

