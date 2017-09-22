#include <cstdio>
#include <cmath>
using namespace std;
double x, y;
int main() {
	scanf("%lf,%lf", &x, &y);
	if ((abs(x) <= 1) && (abs(y) <= 1)) printf("%s", "yes");
	else printf("%s", "no");
}