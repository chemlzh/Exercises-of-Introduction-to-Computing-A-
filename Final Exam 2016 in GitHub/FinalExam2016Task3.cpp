#include <cstdio>
#include <cstring>
long n, flag, tmp;
char password[55];
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%s", password);
		if (strlen(password) < 6) printf("%s\n", "Not safe");
		else {
			flag = 0, tmp = 0;
			for (long i = 0; i < strlen(password); i++) {
				if (password[i] >= '0'&&password[i] <= '9') flag = flag | 1;
				else if (password[i] >= 'A'&&password[i] <= 'Z')  flag = flag | 2;
				else if (password[i] >= 'a'&&password[i] <= 'z') flag = flag | 4;
				else flag = flag | 8;
				if (flag == 15) break;
			}
			while (flag) tmp += flag & 1, flag = flag >> 1;
			if (tmp == 1) printf("%s\n", "Not safe");
			else if (tmp == 2) printf("%s\n", "Medium safe");
			else if (tmp >= 3) printf("%s\n", "Safe");
		}
	}
}