#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define INF 0x3f3f3ff
const int maxn=500005;

struct Node
{
    int v,w,next;     //体现链式
}edges[maxn];

int id,head[maxn],visit[maxn],dist[maxn];

void init()
{
    fill(head,head+maxn,-1);
}

void addedge(int u,int v,int w)
{
    edges[id].v=v;
    edges[id].w=w;
    edges[id].next=head[u];     //指向u节点的第一条边
    head[u]=id++;    //替换这个第一条边
}

void spfa(int st)
{
    fill(visit,visit+maxn,0);
    fill(dist,dist+maxn,-INF);

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
            if(dist[v]<dist[now]+w)
            {
                dist[v]=dist[now]+w;
                if(!visit[v])
                {
                    Q.push(v);
                    visit[v]=1;
                }
            }
        }
    }
}

void solve()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        init();
        id=0;
        int maxnum=0,minnum=INF;
        int u,v,w;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            maxnum=max(maxnum,v+1);
            minnum=min(minnum,u);
            addedge(u,v+1,w);    //坐标向后面移一位
        }
        for(int i=minnum;i<maxnum;i++)
        {
            addedge(i,i+1,0);
            addedge(i+1,i,-1);   //隐含信息，每一个节点只有最多只能存放一个点
        }
        spfa(minnum);
        printf("%d\n",dist[maxnum]);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}