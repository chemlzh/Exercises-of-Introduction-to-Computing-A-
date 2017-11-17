#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const long Alphabet[27] = { 1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,1,7,7,8,8,8,9,9,9,1 };
const long Pow10[8] = { 1,10,100,1000,10000,100000,1000000,10000000 };
long n, now, cnt, flag1 = 0, flag2 = 0, phone[100005];
char c, tmp[20];

inline long Trans(char str[], long len) {
	long ans = 0;
	for (long i = 0; i < len; i++) {
		if (str[i] == '-') continue;
		else if (str[i] >= '0'&&str[i] <= '9')
			ans = ans * 10 + str[i] - '0';
		else if (str[i] >= 'A'&&str[i] <= 'Z')
			ans = ans * 10 + Alphabet[str[i] - 'A' + 1];
	}
	return ans;
}

inline void PrintNumber(long num, long count) {
	for (long j = 6; j >= 0; j--) {
		printf("%ld", num % Pow10[j + 1] / Pow10[j]);
		if (j == 4) printf("%c", '-');
	}
	printf(" %ld\n", count);
}

int main() {
	scanf("%ld%c", &n, &c);
	for (long i = 1; i <= n; i++) {
		scanf("%s", tmp), phone[i] = Trans(tmp, strlen(tmp));
	}
	sort(phone + 1, phone + n + 1), phone[0] = -1, cnt = 1, now = phone[1];
	for (long i = 2; i <= n; i++) {
		if (phone[i] == phone[i - 1]) flag2 = 1, cnt++;
		else {
			if (cnt != 1) PrintNumber(now, cnt);
			cnt = 1, now = phone[i];
		}
	}
	if (!flag2) printf("%s", "No duplicates.");
	else if (cnt != 1) PrintNumber(now, cnt);
}