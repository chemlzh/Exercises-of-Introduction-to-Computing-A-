#include <cstdio>
#include <cstring>
long target, material, minsum;
long sum, count, ans[10];
long step[10];
long m[10];
void dfs(long now, long pos) {
	if (pos == 0) {
		if (now <= target&&now == sum) count++;
		else if (now <= target&&now > sum) {
			sum = now, count = 1, memcpy(ans, step,sizeof(ans));
		}
	}
	else {
		for (long i = pos; i >= 1; i--) {
			long tmp = 0;
			for (long j = pos; j >= i; j--) tmp = tmp * 10 + m[j];
			if (tmp + now > target) break;
			else if (sum == target&&count > 1) break;
			step[++step[0]] = tmp;
			dfs(tmp + now, i - 1);
			step[step[0]--] = 0;
		}
	}
}
int main() {
	for (;;) {
		scanf("%ld%ld", &target, &material);
		if (target==0&&material==0) break;
		else if (target == 0 && material != 0) printf("%s\n", "error");
		else if (target > material) printf("%ld %ld\n", material, material);
		else {
			m[0] = 0, sum = -1, count = 0;
			while (material) m[++m[0]] = material % 10, material /= 10;
			dfs(0, m[0]);
			if (sum < 0) printf("%s\n", "error");
			else if (count > 1) printf("%s\n", "rejected");
			else {
				printf("%ld", sum);
				for (long i = 1; i <= ans[0]; i++) printf(" %ld", ans[i]);
				printf("\n");
			}
		}
	}
}