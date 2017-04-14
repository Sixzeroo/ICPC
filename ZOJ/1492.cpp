#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int maxn=55;

bool G[maxn][maxn];
int Max[maxn],Alt[maxn][maxn],ans,n;

bool dfs(int cur,int tot)     //cur 当前层次集合大小  tot 所在的层次
{
	if(cur==0)
	{
		if(tot>ans)
		{
			ans=tot;
			return 1;
		}
		return 0;
	}
	for(int i=0;i<cur;i++)
	{
		if(cur-i+tot<=ans) return 0;    //剪枝1
		int u=Alt[tot][i];    //选取当前考虑的点
		if(Max[u]+tot<=ans) return 0;
		int next=0;
		for(int j=i+1;j<cur;j++)
		{
			if(G[u][Alt[tot][j]])  Alt[tot+1][next++]=Alt[tot][j];
		}
		if(dfs(next,tot+1)) return 1;
	}
	return 0;
}

void  MaxClique()
{
	ans=0;
	memset(Max,0,sizeof(Max));
	for(int i=n-1;i>=0;i--)    //逆向构建Max
	{
		int cur=0;
		for(int j=i+1;j<n;j++) 
			if(G[i][j]) Alt[1][cur++]=j;
		dfs(cur,1);
		Max[i]=ans;
	}
}

void solve()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
            {
                int a;
                scanf("%d",&a);
                if(a==1)G[i][j]=1;
                else G[i][j]=0;
            }
		MaxClique();
		printf("%d\n",ans);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
