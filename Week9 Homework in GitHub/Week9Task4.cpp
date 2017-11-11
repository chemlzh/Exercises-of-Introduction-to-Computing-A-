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
���������˺ܾã�һ��ʼ��ģ�⣬���Ǻ�֮����ַ������������˳������Ƚϣ������ִ˷������⣬�ʷ�����
����������֪�������Ƕ�̬�滮����״̬Ϊf[i][j]��i��ʾ��ͨ������ַ����ĳ��ȣ�j��ʾ����ͨ������ַ����ĳ��ȣ�
��ת�Ʒ���Ϊf[i][j]=1 (��sample[i]!='*'����j>0��f[i-1][j-1]==1��sample[i]==target[j]��sample[i]=='?')
f[i][j]=1����sample[i]=='*'����f[i-1][k]=1��0<=k<=j����
*/