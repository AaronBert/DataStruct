
/*
 *结合队列 图的广度优先搜索
 */
#include<stdio.h>
#define N 101			//图的最大的顶点个数
int main()
{
	int i,j,n,m,a,b,cur;
	int book[N]={0};
	int edge[N][N];
	int	que[10001],head,tail;
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

	//队列初始化
	head=1;
	tail=1;

	//从1号顶点出发，将1号顶点加入队列,并将其标记为已被访问
	que[tail]=1;
	tail++;
	book[1]=1;

	//广度优先搜索的核心代码
	//当循环队列不为空的时候进行循环
	while(head<tail && tail<=n){
		//获取当前正在访问的顶点编号
		cur = que[head];
		//遍历所有的节点
		for(i=1;i<=n;i++){
			//判断从当前顶点cur到顶点i是否有关系（边），并判断顶点i是否已经访问过了
			if(edge[cur][i]==1 && book[i]==0){
				//顶点cur与i之间有关系（边），并且没有被访问过，则将其纳入队列之中，并将其状态设置为已被访问
				que[tail]=i;
				tail++;
				book[i]=1;
			}
			//如果tail>n,则表明所有顶点都已被访问过了，则循环结束
			if(tail>n)
				break;
		}

		/*
		 *ＰＳ：当一个节点扩展结束之后，ｈｅａｄ＋＋（即访问下一个即将被扩展的节点）
		 *　　　然后才可以继续往下扩展
		 */
		head++;
	}

	//输出队列的结果，即广度优先搜索的顶点访问顺序
	for(i=1;i<tail;i++)
		printf("%d ",que[i]);
	
	getchar();
	getchar();
	return 0;
	 
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
1 2 3 5 4
*/
