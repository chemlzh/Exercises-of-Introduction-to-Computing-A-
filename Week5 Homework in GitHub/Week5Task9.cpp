#include <cstdio>
long flag,seven[4],nine[4];
void transform(long number,long format,long target[]) {
	long temp = number,p=1;
	if (!number) { target[0] = 1; return; }
	target[0] = 0;
	while (temp) { target[++target[0]] = temp%format; temp /= format; }
}
int main() {
	scanf("%ld", &flag);
	for (long i = 81; i <= 342; i++) {
		bool f = true;
		transform(i, 7, seven);
		transform(i, 9, nine);
		for (long j = 1; j <= 3; j++) if (seven[j] != nine[4 - j]) f = false;
		if (f) {
			if (flag == 1) printf("%ld", i);
			else if (flag == 2) for (long j = seven[0]; j >= 1; j--) printf("%ld", seven[j]);
			else if (flag == 3) for (long j = nine[0]; j >= 1; j--) printf("%ld", nine[j]);
			break;
		}
	}
}