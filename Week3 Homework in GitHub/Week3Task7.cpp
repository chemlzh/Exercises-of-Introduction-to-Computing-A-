#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
double k,root,now;
long i;
int main() {
	while (cin >> k) {
		root = 1; i = 0;
		for (;;){
			now = root / 2 + k / (2 * root); i++;
			if (abs(now - root) <= 0.000001) break;
			else root = now;
		} 
		cout << i << ' '<< setprecision(2)<< setiosflags(ios::fixed)<< root << endl;
	}
}