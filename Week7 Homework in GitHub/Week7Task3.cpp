#include <cstdio>
struct student { long id, chinese,math; }ans[5],tmp;
long n,cnt;
inline bool cmp(student s1, student s2) {
	if  (s1.chinese + s1.math > s2.chinese + s2.math) return true;
	else if (s1.chinese + s1.math == s2.chinese + s2.math&&s1.id < s2.id) return true;
	return false;
}
inline void insert(student s) {
	long flag = cnt;
	while (flag > 0 && cmp(s,ans[flag])) { ans[flag + 1] = ans[flag];  flag--; }
	ans[flag + 1] = s;
	if (cnt < 3) cnt++;
}
int main() {
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++) {
		scanf("%ld%ld%ld", &tmp.id, &tmp.chinese, &tmp.math);
		insert(tmp);
	}
	for (long i = 1; i <= 3; i++) printf("%ld %ld\n", ans[i].id, ans[i].chinese + ans[i].math);
}

//ע�⣺ԭ�Ⲣû��˵�������λѧ���ܳɼ���ͬ�������С�����ȣ��������ݱ�����������������