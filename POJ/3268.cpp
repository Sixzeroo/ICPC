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

#define SIZE_V 1005
#define INF 0x3f3f3f3f

struct edge
{
    int to,cost;
};
typedef pair<int,int> p;  //最短距离和顶点编号组成的集合，主要用于优先队列的使用中

int V,E;
vector<edge> G[SIZE_V]; //邻接链表表示图
vector<edge> G1[SIZE_V];  //反向边
int d1[SIZE_V];
int d2[SIZE_V];

void dijkstra(int s)
{
    priority_queue<p,vector<p>, greater<p> > que;
    fill(d1,d1+V+1,INF);
    d1[s]=0;
    que.push(p(0,s));    //初始化优先队列，加入原点

    while(!que.empty())
    {
        p ne=que.top();
        que.pop();
        int v=ne.second;
        if(d1[v]<ne.first)continue;    //新加进来的边没有优化作用
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d1[e.to]>d1[v]+e.cost)  //松弛操作并将新的点加入到优先队列当中
            {
                d1[e.to]=d1[v]+e.cost;
                que.push(p(d1[e.to],e.to));
            }
        }
    }

    fill(d2,d2+V+1,INF);
    d2[s]=0;
    que.push(p(0,s));
    while(!que.empty())
    {
        p ne=que.top();
        que.pop();
        int v=ne.second;
        if(d2[v]<ne.first)continue;
        for(int i=0;i<G1[v].size();i++)
        {
            edge e=G1[v][i];
            if(d2[e.to]>d2[v]+e.cost)
            {
                d2[e.to]=d2[v]+e.cost;
                que.push(p(d2[e.to],e.to));
            }
        }
    }
}

void solve()
{
    int x;
    while(cin>>V>>E>>x)
    {
        int h,t,c;
        edge tem;
        for(int i=0;i<E;i++)
        {
            cin>>h>>t>>c;
            tem.cost=c;
            tem.to=t;
            G[h].push_back(tem);
            tem.to=h;
            G1[t].push_back(tem);
        }
        dijkstra(x);
        int imax=0;
        for(int i=1;i<=V;i++)
            imax=max(imax,d1[i]+d2[i]);
        cout<<imax<<endl;
    }

}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
