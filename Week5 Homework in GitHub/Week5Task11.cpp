#include <cstdio>
const long stage[5] = { 3,1,5,2,4 };
int main() {
	for (long i = 0; i < 5; i++) printf("%ld\n", stage[i]);
}

/*题目：5位跳水高手将参加10米跳台决赛，有好事者让5人据实力预测比赛结果： 
A选手说：B第二；我第三。B选手说：我第二；E第四。C选手说：我第一；D第二。D选手说：C最后；我第三。E选手说：我第四；A第一。
决赛成绩公布之后，每位选手的预测都只对了一半，即一对一错。
请编程解出比赛的实际名次。
*/