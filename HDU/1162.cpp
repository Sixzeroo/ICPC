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

double cost[maxn][maxn];
double mincost[maxn];  //到已经确定的点的最短距离
bool used[maxn];
int V;
double xx[maxn],yy[maxn];

double get_dist(int a,int b)
{
	return sqrt((xx[a]-xx[b])*(xx[a]-xx[b])+(yy[a]-yy[b])*(yy[a]-yy[b]));
}

void build()
{
	for(int i=1;i<=V;i++)
		scanf("%lf %lf",&xx[i],&yy[i]);
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
		{
			cost[i][j]=cost[j][i]=get_dist(i,j);
		}
}

double prim()
{
    fill(mincost,mincost+V+1,INF);  //注意建图方式
    fill(used,used+V+1,false);   //注意建图方式
    mincost[1]=0;        //注意建图方式
    //used[0]=true;     不在这里初始初始化

    double res=0;

    while(true)
    {
        int v=-1;
        for(int i=1;i<=V;i++) //注意建图组织方式
        {
            //在这里对收录一号元素，因为要遍历一号元素的相邻结点
            if(!used[i]&&((v==-1)||mincost[i]<mincost[v]))v=i;   
        }
        if(v==-1)
            break;
        used[v]=true;
        res+=mincost[v];
		//cout<<v<<" "<<res<<endl;
        for(int i=1;i<=V;i++)    //注意建图方式
            mincost[i]=min(mincost[i],cost[v][i]);  //不判断是否相邻
    }
    return res;
}

void solve()
{
	while(scanf("%d",&V)!=EOF)
	{
		build();
		double ans=prim();
		printf("%.2lf\n",ans);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
