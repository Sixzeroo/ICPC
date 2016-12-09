#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;
#define SIZE 2005
#define INF 0x3f3f3f3f

int T,N;
int edge[SIZE][SIZE];
int d[SIZE];
bool used[SIZE];

void dij(int s)
{
    fill(d,d+N,INF);
    fill(used,used+N,false);
    d[s]-0;
    while(1)
    {
        int v=-1;
        for(int i=1;i<=N;i++)
            if(!used[i]&&(v==-1||d[i]<d[v]))v=i;
        if(v==-1)
            break;
        used[v]=true;
        for(int i=1;i<=N;i++)
        {
            if(d[i]>d[v]+edge[v][i])
                d[i]=d[v]+edge[v][i];
        }
    }
}

void solve()
{
    while(~scanf("%d%d",&T,&N))
    {
        memset(edge,INF,sizeof(edge));
        int x,y,c;
        for(int i=0;i<T;i++)
        {
            scanf("%d%d%d",&x,&y,&c);
            edge[x][y]=edge[y][x]=min(c,edge[x][y]);
        }
        dij(N);
        printf("%d",d[1]);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
