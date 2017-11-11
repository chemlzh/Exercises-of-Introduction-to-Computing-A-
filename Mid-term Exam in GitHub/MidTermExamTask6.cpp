#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
stack<long> s;
long n, ans, now, h[20005];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &h[i]);
		if (s.empty()||h[i] >= h[s.top()]) s.push(i);
		else {
			while (!s.empty() && h[s.top()]>h[i]) {
				long num = s.top(); s.pop();
				if (s.empty()) now = h[num] * (i-1); else now = h[num] * (i - s.top()-1);
				ans = max(ans, now);
			}
			s.push(i);
		}
	}
	while (!s.empty()) {
		long num = s.top(); s.pop();
		if (s.empty()) now = h[num] * n; else now = h[num] * (n - s.top());
		ans = max(ans, now);
	}
	printf("%ld", ans);
}

//原题及解析参见cinderalla_niu的博客：http://blog.csdn.net/cinderella_niu/article/details/43493545
/*
本人的理解：此题如果用枚举，并对每个枚举的元素，从中间向两边延伸（比它高的均加入），
那么最坏情况下时间复杂度为O(n^2)，对于量大的点（n=20000）会超时。
因此，我们采用栈的方法，它的时间复杂度为O(n)。
其中栈保存每个矩形元素的编号。如果栈为空或即将进栈的元素不小于栈顶元素，则让该元素进栈。
否则，让栈顶元素出栈，并计算其对应的最大矩形面积，直至栈为空或即将进栈的元素不小于栈顶元素。
如果一个元素出栈后栈非空，那么面积=出栈元素高度*(出栈元素编号-下一个栈顶元素编号)
否则，面积=出栈元素高度*(即将进栈的元素编号-1)。
n次循环后若栈非空，则让栈中元素逐个出栈并计算。
*/