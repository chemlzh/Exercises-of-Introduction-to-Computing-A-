#include <cstdio>
long ans;
double salary, price, sum;
int main() {
	scanf("%lf%lf", &salary, &price);
	for (ans=1;;ans++){
		sum += salary;  
		if ((ans > 100)||(sum>price)) break;
		salary *= 1.08; 
		price *= 1.10;
	}
	if (ans > 100) printf("%s", "Forget it.");
	else printf("%ld", ans);
}