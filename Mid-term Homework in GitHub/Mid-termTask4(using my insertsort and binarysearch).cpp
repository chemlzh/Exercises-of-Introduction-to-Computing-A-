#include <cstdio>
#include <cstring>
long a[205], ans[205], tmp, cnt1, cnt2;
char c;
void InsertSort(long num,long cnt,long ins[]) {
	long pos = cnt;
	ins[0] = num;
	while (pos >= 0 && num<ins[pos]) {
		ins[pos + 1] = ins[pos]; pos--;
	}
	ins[pos + 1] = num;
}
long BinarySearch(long num,long l,long r,long find[]) {
	long left = l, right = r, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (find[mid] == num) return mid;
		else if (find[mid] < num) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
int main() {
	for (;;) {
		scanf("%ld%c", &tmp, &c);
		InsertSort(tmp, cnt1, a); cnt1++;
		if (c == '\n') break;
	}
	for (;;) {
		scanf("%ld%c", &tmp, &c);
		if (BinarySearch(tmp, 1, cnt1, a) != -1 && BinarySearch(tmp, 1, cnt2, ans) == -1) { InsertSort(tmp, cnt2, ans); cnt2++; }
		if (c == '\n') break;
	}
	if (!cnt2) printf("%s", "NULL");
	else {
		for (long i = 1; i <= cnt2; i++) { printf("%ld", ans[i]); if (i != cnt2) printf("%c", ','); }
	}
}