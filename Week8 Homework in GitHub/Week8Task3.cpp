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
����
С������������Ϸ��2k��С����Χ��һ��Ȧ��������δ�1��2k������k�����ݺ��ˣ���k�����ݻ��ˡ�
��Ϸ�������£��ӵ�һ��С����ʼ����������mʱ����m��С�����߳���Ȼ�����һ��С����ʼ���ظ�ǰ��Ĺ��̣�ֱ����ʣ��k��С����ֹͣ���ˡ�
����ϣ�����߳��Ķ��ǻ��ˡ���֪ǰk���Ǻ��ˣ���k���ǻ��ˡ�
����Ҫ�������ÿһ��k��ȷ��һ����С��������m��ʹ�ð���Ϸ�����߳���k����ֽ���ǻ��ˡ�
*/