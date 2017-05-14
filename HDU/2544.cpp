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
const int maxn=105;
const int maxm=10005;
int visit[maxn],dist[maxn],head[maxn];
int n,m,id;

struct Node
{
	int v,w,next;
}edges[maxm];

void addedge(int u,int v,int w)
{
	edges[id].v=v;
	edges[id].w=w;
	edges[id].next=head[u];    //把之前的第一条边作为当前边的最后一条边
	head[u]=id++;
}

void spfa(int st)
{
    fill(visit,visit+maxn,0);
    fill(dist,dist+maxn,INF);
    queue<int> Q;
    visit[st]=1;
    dist[st]=0;
    Q.push(st);
    while (!Q.empty())
    {
        int now=Q.front();
        Q.pop();
        visit[now]=0;
        for(int i=head[now];i!=-1;i=edges[i].next)
        {
            int v=edges[i].v;
            int w=edges[i].w;
            if(dist[v]>dist[now]+w)
            {
                dist[v]=dist[now]+w;
                if(!visit[v])
                {
                    Q.push(v);
                    visit[v]=1;
                }
            }
        }
        /*for(int i=1;i<=n;i++)
			cout<<dist[i]<<" ";
		cout<<endl;*/
    }
}

void solve()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 &&m==0) break;
		memset(head,-1,sizeof(head));
		int u,v,w;
		id=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		spfa(1);
		int ans=dist[n];
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
