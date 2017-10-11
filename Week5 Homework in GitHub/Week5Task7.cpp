#include <algorithm>
#include <cstdio>
using namespace std;
struct event{long start, end; }e[100005];
long n, LastTail, ans;
inline bool cmp(event e1,event e2) {
	if (e1.end < e2.end) return true;
	else if (e1.end > e2.end) return false;
	else if (e1.start > e1.start) return true;
	return false;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) scanf("%ld%ld", &e[i].start, &e[i].end);
	sort(e + 1, e + n + 1, cmp);
	for (long i = 1; i <= n; i++) {
		if (e[i].start >= LastTail) {	ans++;	LastTail = e[i].end;  }
	}
	printf("%ld", ans);
}

/*���ͣ��������߶�����ཻ�������⣬�ⷨ�Ƕ��߶ε��Ҷ˵������������ÿ����һ���߶Σ�
��������Ժ󲻻��֮ǰ���߶β����������֣���ô�ͼ��룬����ͼ����жϺ�����߶Ρ�
̰��֤������Ϊ��Ҫ������Ķ������߶Σ�����ÿ���߶ζ������ܵ�С������ͬһ�Ҷ˵㣬��˵�Խ���߶γ���ԽС��
��ôΪʲôҪ���Ҷ˵���������أ������˵����������ô�Ҷ˵��Ƕ��ٲ���֪����
��ôÿһ���߶ζ����ܶ�֮ǰ���е��߶ν���һ���ܽᣬ��ô������Բ�����̰�ĵ����Ż��ṹ�ˡ�
*/