#include <cstdio>
#include <cstring>
char str[10];
long len, f[10], vis[10];
inline void dfs(long step) {
	if (step == len + 1) {
		for (long i = 1; i <= len; i++) printf("%c", str[f[i] - 1]);
		printf("\n");
		return;
	}
	else {
		for (long i = 1; i <= len; i++) {
			if (!vis[i]) f[step] = i, vis[i] = 1, dfs(step + 1), f[step] = 0, vis[i] = 0;
		}
	}
}
int main() {
	scanf("%s", str), len = strlen(str), dfs(1);
}