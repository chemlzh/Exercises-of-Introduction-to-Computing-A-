#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct FormatNumber { long d, format, num[210]; }n1, n2, ans;
const char digit[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
long a1, b1, p;
char a[105], b[105];
void transform(char number[],long StartFormat,long TargetFormat,FormatNumber &TargetNum) {
	long f = 1, tmp = 0;
	for (long i = strlen(number) - 1; i >= 0; i--) {
		if (number[i] >= '0'&&number[i] <= '9') tmp += (number[i] - '0')*f;
		else tmp += (number[i] - 'a' + 10)*f;
		f *= StartFormat;
	}
	TargetNum.format = TargetFormat; 
	while (tmp) {
		TargetNum.num[++TargetNum.d] = tmp%TargetFormat; tmp /= TargetFormat;
	}
}
void calculate(FormatNumber &num1,FormatNumber &num2,FormatNumber &target) {
	target.d = max(num1.d, num2.d)+1;
	target.format = num1.format;
	for (long i = 1; i <= target.d; i++) {
		target.num[i] += num1.num[i] + num2.num[i];
		target.num[i + 1] += target.num[i] / target.format;
		target.num[i] %= target.format; 
	}
	while (!target.num[target.d]&&target.d>1) target.d--;
}
void print(FormatNumber &num) {
	for (long i = num.d; i >= 1; i--) printf("%c", digit[num.num[i]]);
}
int main() {
	scanf("%ld %s", &a1, &a);
	scanf("%ld %s", &b1, &b);
	scanf("%ld", &p);
	transform(a, a1, p, n1); transform(b, b1, p, n2); 
	calculate(n1, n2, ans);
	print(ans);
}