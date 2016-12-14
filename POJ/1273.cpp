#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<utility>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<sstream>

using namespace std;

#define SIZE_V 300
#define SIZE_E 100000
#define INF 0x3f3f3f3f
typedef long long ll;

int G[SIZE_V][SIZE_V];
int prev[SIZE_V];   //每个结点对应的前驱结点
bool visited[SIZE_V];
int V,E;

int Augment()  //使用bfs一次找出一条增广路
{
    int v,i;
    queue<int> q;
    memset(prev,0,sizeof(prev));
    memset(visited,0,sizeof(visited));
    prev[1]=0;
    visited[1]=1;
    q.push(1);
    bool bfindpath=0; //标识是否找到增广路
    while(!q.empty())
    {
        v=q.front();
        q.pop();
        for(i=1;i<=V;i++)
        {
            if(G[v][i]>0&&!visited[i]) //边上依然有容量可以走
            {
                prev[i]=v;
                visited[i]=1;
                if(i==V)  //找到一条增广路
                {
                    bfindpath=true;
                    q=queue<int> ();   //清空队列
                    break;
                }
                else
                    q.push(i);
            }
        }
    }
    if(!bfindpath)  //没有找到增广路
        return 0;
    //找出这条流的流量，即增广路上的最小边
    int minflow=INF;
    v=V;
    while(prev[v])
    {
        minflow=min(minflow,G[prev[v]][v]);    //注意是正向流量
        v=prev[v];
    }
    //改变流量，添加反向边
    v=V;
    while(prev[v])
    {
        G[prev[v]][v]-=minflow;
        G[v][prev[v]]+=minflow;
        v=prev[v];
    }
    return minflow;
}

void solve()
{
    while(cin>>E>>V)
    {
        int i,j,k;
        int s,e,c;
        memset(G,0,sizeof(G));
        for(i=0;i<E;i++)
        {
            cin>>s>>e>>c;
            G[s][e]+=c;    //累加方式处理重边
        }
        int maxflow=0;
        int aug;
        while(aug=Augment())
            maxflow+=aug;  //通过寻找增广路，不断增加新的流量进来
        cout<<maxflow<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
