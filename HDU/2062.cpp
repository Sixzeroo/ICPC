#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int maxn=1006;

int matching[maxn],head[maxn];
bool visit[maxn];
int cnt,P,N;

struct Edge
{
	int to;
	int next;
};

Edge edge[maxn*maxn];

void Init()
{
	cnt=0;
	memset(head,-1,sizeof(head));
}

void add(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}

bool dfs(int u)
{
	for(int i=head[u];~i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!visit[v])
		{
			visit[v]=1;
			if(matching[v]==-1|| dfs(matching[v]))
			{
				matching[v]=u;
				return true;
			}
		}
	}
	return false;
}

int huangay()
{
	int ans=0;
	memset(matching,-1,sizeof(matching));
	for(int i=1;i<=P;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i)) ans++;
	}
	return ans;
}

void solve()
{
	int t;
    scanf("%d",&t);
	while(scanf("%d %d",&P,&N)!=EOF)
	{
        Init();
		int a,b;
		for(int i=0;i<t;i++)
		{
			scanf("%d %d",&a,&b);
			add(a,b);
		}
		printf("%d\n",huangay());
        scanf("%d",&t);
        if(t==0)
            break;
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
