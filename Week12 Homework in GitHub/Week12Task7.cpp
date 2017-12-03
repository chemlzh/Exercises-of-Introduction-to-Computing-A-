#include <cstdio>
#include <cstring>
const char fruit[7][15] = { "apples", "bananas", "peaches", "cherries", "pears", "oranges", "strawberries" };
long cnt;
char c, t[1005];
int main() {
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			long flag = 0;
			for (long i = 0; i < 7; i++) {
				char *tmp = strstr(t, fruit[i]);
				if (tmp != NULL) {
					for (long j = 0; j < tmp - t; j++) printf("%c", t[j]);
					printf("%s", "Brussels sprouts");
					for (long j = tmp - t + strlen(fruit[i]); j < strlen(t); j++) printf("%c", t[j]);
					printf("\n"), flag = 1; break;
				}
			}
			if (!flag) printf("%s\n", "You must not enjoy fruit.");
			memset(t, '\0', sizeof(t)), cnt = 0;
		}
		else t[cnt++] = c;
	}
}