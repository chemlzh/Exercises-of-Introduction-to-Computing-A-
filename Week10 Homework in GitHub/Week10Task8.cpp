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

//�����������������ַ���������ԣ��ɲ���ֻ�������������������
//���������Ǽ���ң���Ŀ��û���������