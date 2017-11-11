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

//ԭ�⼰�����μ�cinderalla_niu�Ĳ��ͣ�http://blog.csdn.net/cinderella_niu/article/details/43493545
/*
���˵���⣺���������ö�٣�����ÿ��ö�ٵ�Ԫ�أ����м����������죨�����ߵľ����룩��
��ô������ʱ�临�Ӷ�ΪO(n^2)����������ĵ㣨n=20000���ᳬʱ��
��ˣ����ǲ���ջ�ķ���������ʱ�临�Ӷ�ΪO(n)��
����ջ����ÿ������Ԫ�صı�š����ջΪ�ջ򼴽���ջ��Ԫ�ز�С��ջ��Ԫ�أ����ø�Ԫ�ؽ�ջ��
������ջ��Ԫ�س�ջ�����������Ӧ�������������ֱ��ջΪ�ջ򼴽���ջ��Ԫ�ز�С��ջ��Ԫ�ء�
���һ��Ԫ�س�ջ��ջ�ǿգ���ô���=��ջԪ�ظ߶�*(��ջԪ�ر��-��һ��ջ��Ԫ�ر��)
�������=��ջԪ�ظ߶�*(������ջ��Ԫ�ر��-1)��
n��ѭ������ջ�ǿգ�����ջ��Ԫ�������ջ�����㡣
*/