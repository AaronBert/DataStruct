#include<stdio.h>
#define N 101				//改程序可承受的最大的顶点个数100

//全局变量声明
int book[N];				//标记--改点是否被访问过
int sum;					//被访问的点的个数
int n;						//总的顶点个数
int edge[N][N];				//图的邻接矩阵

//深度优先搜索核心函数 方法声明
void dfs(int cur);			//cur表示当前所在的顶点编号

int main()
{

	int i,j,m,a,b;
	scanf("%d %d",&n,&m);
	//初始化二维矩阵
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
				edge[i][j]=0;
			else
				//设999999为无穷大，即边之间没有关系
				edge[i][j]=999999;

		}
	}

	//读入顶点之间的边
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		edge[a][b]=1;
		edge[b][a]=1;
	}

	//从第一个顶点出发,并将第一个顶点标记为已被访问
	book[1]=1;
	//开始递归调用
	dfs(1);
	getchar();
	getchar();
	return 0;
	 
} 

void dfs(int cur){
	int i;
	//先输出当前出发点
	printf("%d ",cur);
	//每访问过一个顶点，sum++
	sum++;
	//递归出口
	if(sum==n){
		//如果所有的点均被访问，退出程序
		return ;
	}

	//对所有的顶点依次遍历，看哪些顶点与当前顶点cur右边相连的关系
	for(i=1;i<=n;i++){
		//判断当前顶点cur到点i是否右边，并且这个点是否被访问过
		if(edge[cur][i]==1&&book[i]==0){
			//将改点设置成被访问过得状态
			book[i]=1;
			//从该顶点（即顶点i出发），调用想用的法则进行判定
			dfs(i);
		}
	}
	return ;
}

/*
测试用例
5 5
1 2
1 3
1 5
2 4
3 5
测试结果：
1 2 4 3 5
*/
