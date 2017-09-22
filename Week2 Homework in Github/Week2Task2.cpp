#include <cstdio>
long money,dis;
double ans;
int main() {
	scanf("%ld%ld",&money,&dis);
	if ((dis > 0)&&(dis<=6)) ans = 3.00;
	else if ((dis > 6) && (dis <= 12)) ans = 4.00;
	else if ((dis>12)&&(dis<=32)) ans =4.00+(dis-12+9)/10 ;
	else if (dis > 32) ans = 6.00 + (dis - 32 + 19) / 20;
	if ((money >= 100) && (money < 150)) ans *= 0.8;
	if ((money >= 150) && (money < 400)) ans *= 0.5;
	printf("%.2f", ans);
}