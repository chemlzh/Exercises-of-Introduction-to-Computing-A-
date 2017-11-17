#include <cstdio>
#include <cstring>
struct PhoneNumber { long cnt, num; }p[100005];
const long Alphabet[27] = { 1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,1,7,7,8,8,8,9,9,9,1 };
long n, phone, cnt, flag1 = 0, flag2 = 0;
char c, tmp[20];

inline bool SearchWithInsertion(long num) {
	long left = 1, right = cnt, mid = (1 + cnt) / 2, f = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (p[mid].num == num) { f = 1; break; }
		else if (p[mid].num > num) right = mid - 1;
		else left = mid + 1;
	}
	if (f) { p[mid].cnt++; return true; }
	else {
		if (p[mid].num < num) mid++;
		for (long i = cnt; i >= mid; i--) p[i + 1] = p[i];
		p[mid].num = num, p[mid].cnt = 1, cnt++;
		return false;
	}
}

int main() {
	scanf("%ld%c", &n, &c);
	for (long i = 1; i <= n; i++) {
		scanf("%s", tmp), phone = 0;
		for (long j = 0; j < strlen(tmp); j++) {
			if (tmp[j] == '-') continue;
			else if (tmp[j] >= '0'&&tmp[j] <= '9') 
				phone = phone * 10 + tmp[i] - '0';
			else if (tmp[j] >= 'A'&&tmp[j] <= 'Z') 
				phone = phone * 10 + Alphabet[tmp[j] - 'A' + 1];
		}
		if (SearchWithInsertion(phone)) flag1 = 1;
	}
	if (!flag1) printf("%s", "No duplicates.");
	else {
		for (long i = 1; i <= cnt; i++)
			if (p[i].cnt > 1)
				printf("%ld-%ld %ld\n", p[i].num / 10000, p[i].num % 10000, p[i].cnt), flag2 = 1;
		if (!flag2) printf("%s", "No duplicates.");
	}
}