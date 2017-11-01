#include <cstdio>
#include <cstring>
long k, m, flag[30], ans[15] = { 0,2,7,5,30 };
int main() {
	for (;;) {
		scanf("%ld", &k);
		if (k == 0) return 0;
		else if (ans[k]) { printf("%ld\n", ans[k]); continue;	}
		for (long a = 0;; a++) {
			long tmp, tmp1, f, r;
			for (long b = k + 1; b <= 2 * k; b++) {
				memset(flag, 0, sizeof(flag));
				tmp = 0, f = 1, r = 2 * a*k + b;
				for (long i = 1; i <= k; i++) {
					tmp1 = r % (2 * k - i + 1);
					if (!tmp1) tmp1 = 2 * k - i + 1;
					for (long j = 1; j <= tmp1; j++) {
						do { tmp = tmp % (2 * k) + 1; } while (flag[tmp]);
					}
					if (tmp <= k) { f = 0; break; }
					else flag[tmp] = 1;
				}
				if (f) { printf("%ld\n", r); ans[k] = r; break; }
			}
			if (f) break;
		}
	}
}
/*
描述
小朋友们在玩游戏：2k个小朋友围成一个圈，标号依次从1到2k，其中k个扮演好人，另k个扮演坏人。
游戏规则如下：从第一个小孩开始报数，报到m时，第m个小孩被踢出，然后从下一个小孩开始，重复前面的过程，直到还剩下k个小孩，停止踢人。
我们希望被踢出的都是坏人。已知前k个是好人，后k个是坏人。
现在要求你对于每一个k，确定一个最小的正整数m，使得按游戏规则踢出的k个孩纸都是坏人。
*/