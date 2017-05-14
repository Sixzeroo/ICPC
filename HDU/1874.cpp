#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn=205;
const int maxm=2005;

int cost[maxn][maxn];  //邻接矩阵建图
int d[maxn];
bool used[maxn];  //表示是否被收录
int V,E;

//建图
void build()
{
	memset(d,INF,sizeof(d));
	memset(cost,INF,sizeof(cost));    //初始化邻接矩阵
	int u,v,w;
	for(int i=0;i<E;i++)
	{
        scanf("%d %d %d",&u,&v,&w);
        cost[u][v]=cost[v][u]=min(cost[v][u],w);  //去重边操作
	}
}

void dijkstra(int s)
{
    fill(d,d+V,INF);
    fill(used,used+V,false);
    d[s]=0;
    while(true)
    {
        int v=-1;
        //从未被收录的点中找出一个距离最小的点
        for(int j=0;j<V;j++)
        {
            if(!used[j]&&(v==-1||d[j]<d[v]))v=j;  //v==-1设置哨兵，确定有没有没被收录的点
        }

        if(v==-1)
            break;
        used[v]=true;
        for(int i=0;i<V;i++)
            d[i]=min(d[i],d[v]+cost[v][i]);  //松弛操作
    }
}

void solve()
{
	int S,T;
	while(scanf("%d %d",&V,&E)!=EOF)
	{
		build();
		scanf("%d %d",&S,&T);
		dijkstra(S);
		int ans=d[T];
		printf("%d\n",ans==INF?-1:ans);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
