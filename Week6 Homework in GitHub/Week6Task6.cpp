#include <cstdio>
long n,map[105][105],vis[105][105],area,cir;
void floodfill(long x, long y) {
	vis[x][y] = 1; area++;
	if (x == 1 || y == 1 || x == n || y == n) cir++;
	else if (map[x - 1][y] > 50 || map[x + 1][y] > 50 || map[x][y - 1] > 50 || map[x][y + 1] > 50) cir++;
	if (x > 1 && map[x - 1][y] <= 50 && vis[x - 1][y] == 0) floodfill(x - 1, y);
	if (x < n&&map[x + 1][y] <= 50 && vis[x + 1][y] == 0) floodfill(x + 1, y);
	if (y > 1 && map[x][y - 1] <= 50 && vis[x][y - 1] == 0) floodfill(x, y - 1);
	if (y < n&&map[x][y + 1] <= 50 && vis[x][y + 1] == 0) floodfill(x, y + 1);
}
int main() {
	scanf("%ld",&n);
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) scanf("%ld", &map[i][j]);
	}
	for (long i = 1; i <= n; i++) {
		for (long j = 1; j <= n; j++) if (!vis[i][j] && map[i][j] <= 50) floodfill(i, j);
	}
	printf("%ld %ld", area, cir);
}

/*
描述
一张CT扫描的灰度图像可以用一个N*N（0< N< 100）的矩阵描述，矩阵上的每个点对应一个灰度值（整数），其取值范围是0-255。
我们假设给定的图像中有且只有一个肿瘤。在图上监测肿瘤的方法如下：如果某个点对应的灰度值小于等于50，则这个点在肿瘤上，否则不在肿瘤上。
我们把在肿瘤上的点的数目加起来，就得到了肿瘤在图上的面积。
任何在肿瘤上的点，如果它是图像的边界或者它的上下左右四个相邻点中至少有一个是非肿瘤上的点，则该点称为肿瘤的边界点。
肿瘤的边界点的个数称为肿瘤的周长。
现在给定一个图像，要求计算其中的肿瘤的面积和周长。

输入
输入第一行包含一个正整数N (0< N< 100) 表示图像的大小；
接下来N行，每行包含图像的一行。图像的一行用N个整数表示（所有整数大于等于0，小于等于255），两个整数之间用一个空格隔开。

输出
输出只有一行，该行包含两个正整数，分别为给定图像中肿瘤的面积和周长，用一个空格分开。
*/

/*
解法：大水漫灌法，用DFS实现。
*/