#include <cstdio>
#include <cstring>
char s[305], s1[15], s2[15];
long pos1[305], pos2[305];
inline void init(char str[]) {
	long cnt = 0;
	char tmp = getchar();
	while (tmp != ',' &&tmp != '\n') {
		str[cnt++] = tmp,	tmp = getchar();
	}
}
inline void find(char target[],char str[],long pos[]) {
	long p = 0, lenT = strlen(target), lenS = strlen(str);
	if (lenT < lenS) return;
	while (p <= strlen(target)) {
		bool flag = true;
		for (long i = p; i <= p + lenS - 1; i++) { if (target[i] != str[i - p]) flag = false; }
		if (flag) pos[++pos[0]] = p,p += lenS;
		else p++;
	}
}
int main() {
	init(s), init(s1), init(s2);
	find(s,s1,pos1), find(s,s2,pos2);
	if ((!pos1[0]) || (!pos2[0])) printf("%ld", -1);
	else if (pos1[1] + strlen(s1) - 1 >= pos2[pos2[0]]) printf("%ld", -1);
	else printf("%ld", pos2[pos2[0]] - pos1[1] - strlen(s1));
}