/*
输入为n行m列的矩阵, 矩阵中的元素为数字0或1，其中数字1代表陆地，数字0代表水，你有一个两栖交通工具走陆地费用为1水路费用为2，请你计算从网格的左上角行驶到右下角的最小费用。原题为核心代码模式。
测试用例
输入：
4 5
1 0 1 1 0
0 1 0 1 0
1 1 0 0 1
0 0 0 0 1
输出：
5
*/
//#include<iostream>
//#include<queue>
//using namespace std;
//
//struct node {
//	int x, y, v;
//	node(int a, int b, int c) {
//		 x = a;
//		 y = b;
//		 v = c;
//
//	}
//};
//int fxy[8][2] = { {0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };
//
//const int maxn = 100;
//int maze[maxn][maxn];
//int visit[maxn][maxn];
//int m, n;
//
//int minspend = 100000;
//int BFS(int xindex, int yindex) 
//{
//	queue<node>q;
//	node start = node(xindex, yindex, 0);
//	q.push(start);
//	fill(&visit[0][1], &visit[maxn - 1][maxn - 1] + 1, 100000);
//	while (!q.empty())
//	{
//		node cen = q.front();
//		q.pop();
//		if (cen.x==m-1 && cen.y==n-1)
//		{
//			if (cen.v<minspend)
//			{
//				minspend = cen.v;
//			}
//
//		}
//		for (int i = 0; i < 8; i++)
//		{
//			int newx = cen.x + fxy[i][0];
//			int newy = cen.y + fxy[i][1];
//			if (newx>=0 && newx<=m-1 && newy>=0 && newy<=n-1)
//			{
//				int newv = cen.v + maze[newx][newy];
//				if (newv < visit[newx][newy])
//				{
//					visit[newx][newy] = newv;
//					q.push(node(newx, newy, newv));
//				}
//				
//				
//			}
//
//		}
//	}
//	return minspend;
//}
//
//
//
//int main()
//{
//	cin >> m >> n;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> maze[i][j];
//			if (maze[i][j]==0)
//			{
//				maze[i][j] = 2;
//			}
//			visit[i][j] = 0;
//		}
//
//	}
//	int xindex = 0;
//	int yindex = 0;
//	int result = 0;
//	result = BFS( xindex,  yindex);
//	cout << result << endl;
//
//	return 0;
//}


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node {
	int x, y;
	node(int a, int b)
	{
		x = a; y = b;
	}
};
const int maxn = 10;
int maze[maxn][maxn];
int visit[maxn][maxn];
int m, n;
int fxy[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
queue<node>q;

void BFS()
{

	while (!q.empty())
	{
		node cen = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newx = cen.x + fxy[i][0];
			int newy = cen.y + fxy[i][1];
			if (newx > 0 && newx < m - 1 && newy>0 && newy < n - 1 && maze[newx][newy] == 0 && visit[newx][newy] == 0)
			{

				visit[newx][newy] = 1;
				q.push(node(newx, newy));

			}

		}
	}


}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
			if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && maze[i][j] == 0)
			{
				q.push(node(i, j));
				maze[i][j] = 3;
			}
			visit[i][j] = 0;
		}

	}
	BFS();
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == 0 && maze[i][j] == 0)
			{
				maze[i][j] = 2;
			}
			if (maze[i][j] == 3)
			{
				maze[i][j] = 0;
			}

			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}