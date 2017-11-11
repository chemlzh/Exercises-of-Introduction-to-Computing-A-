#include <cstdio>
#include <cstring>
long cnt = 1, lenS, lenT, f[25][25];
char c, sample[25], target[25];
inline void init(char s[]) {
	long len = 0;
	c = getchar();
	while (c != '\n') s[len++] = c, c = getchar();
}
int main() {
	init(sample), lenS = strlen(sample);
	init(target), lenT = strlen(target);
	f[0][0] = 1;
	for (long i = 1; i <= lenS; i++) {
		for (long j = 0; j <= lenT; j++)
		{
			if (sample[i - 1] == '*') {
				for (long k = j; k >= 0; k--) {
					if (f[i - 1][k]) { f[i][j] = 1; break; }
				}
			}
			else if ((sample[i - 1] == target[j - 1] || sample[i - 1] == '?') && (j&&f[i - 1][j - 1])) f[i][j] = 1;
		} 
	}
	if (f[lenS][lenT]) printf("%s", "matched"); else printf("%s", "not matched");
}

/*
这题我想了很久，一开始想模拟，将星号之间的字符串拆出来，按顺序逐个比较，但发现此法有问题，故放弃。
最后查了题解才知道正解是动态规划。记状态为f[i][j]，i表示带通配符的字符串的长度，j表示不带通配符的字符串的长度，
则转移方程为f[i][j]=1 (当sample[i]!='*'，且j>0，f[i-1][j-1]==1，sample[i]==target[j]或sample[i]=='?')
f[i][j]=1（当sample[i]=='*'，且f[i-1][k]=1（0<=k<=j））
*/