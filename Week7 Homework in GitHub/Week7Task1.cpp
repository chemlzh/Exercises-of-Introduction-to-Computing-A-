#include <iostream>
#include <cstdio>
#include <cstring>
char str[105];
long len, tail;
int main(){
	do { 	str[len++] = getchar();	} while (str[len-1] != '\n');
	len--; tail = len-1;
	for (long i = len - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			for (long j = i + 1; j <= tail; j++) printf("%c", str[j]);
			printf(" "); tail = i - 1;
		}
		else if (!i) {
			for (long j=0;j<=tail;j++) printf("%c", str[j]);
		}
	}
}