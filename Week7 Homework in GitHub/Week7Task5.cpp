#include <cstdio>
#include <cstring>
struct words{ char str[25]; long cnt; }dict[3005],tmp;
long cnt;
char c;
int main() {
	for (;;) {
		c = getchar();
		if (c == '\n') break;
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')||c==39) tmp.str[strlen(tmp.str)] = c;
		else {
			if (tmp.str[0] == '\0') continue;
			else {
				bool flag = false;
				for (long i = 1; i <= cnt; i++) 
					if (!strcmp(tmp.str, dict[i].str)) { dict[i].cnt++; flag = true; break; }
				if (!flag) { cnt++;  dict[cnt].cnt = 1; strcpy(dict[cnt].str, tmp.str); }
				memset(tmp.str, '\0', sizeof(tmp.str));
			}
		}
	}
	for (long i = 1; i <= cnt; i++) printf("%s %ld\n", dict[i].str, dict[i].cnt);
}