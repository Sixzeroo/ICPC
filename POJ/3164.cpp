#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define in(a) scanf("%d",&a)

using namespace std;
const int maxn=110;
#define INF 0x3f3f3f3f

struct edge
{
    int u,v;
    double  w;
    edge(int uu,int vv, double ww):u(uu),v(vv),w(ww){}
};

vector<edge> g;

int id[maxn],pre[maxn],v[maxn];
double inw[maxn],ans;
int n,m;
int xx[maxn],yy[maxn];

double getdis(int a,int b)
{
    double ret= sqrt(double((yy[b]-yy[a])*(yy[b]-yy[a])+(xx[b]-xx[a])*(xx[b]-xx[a])));
    return ret;
}

bool fun(int s)      //存在最小树型图时，返回TRUE，ans；不存在的时候，返回FALSE
{
    ans=0;
    while (true)
    {

        for(int i=0;i<=n;i++)
        {
            inw[i]=INF;
            id[i]=-1;
            v[i]=-1;
            pre[i]=-1;
        }
        //找到每个点的最小入边
        for(int i=0;i<g.size();i++)
            if(g[i].w <=inw[g[i].v] && g[i].v!=g[i].u)
            {
                inw[g[i].v]=g[i].w;
                pre[g[i].v]=g[i].u;
            }
        pre[s]=s;
        inw[s]=0;       //根节点没有入边
        //计算总的权重和
        for(int i=1;i<=n;i++)
        {
            if(inw[i]==INF)
                return false;     //没有找到最小的入边的时候，返回错误
            ans+=inw[i];
        }
        //判断有没有环
        int idx=1;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==-1)     //v[]作用是判断有没有环
            {
                int t=i;
                while (v[t]==-1)
                {
                    v[t]=i;
                    t=pre[t];
                }
                if(v[t]!=i || t==s)
                    continue;      //没有环的时候
                id[t]=idx++;      //重构图中新的点
                for(int j=pre[t];j!=t;j=pre[j])id[j]=idx-1;     //缩点操作，确定前后点的关系
            }
        }
        if(idx==1)
            return true;
        //为不在环中的点建立图之间点的关系
        for(int i=1;i<=n;i++)
            if(id[i]==-1)id[i]=idx++;
        //重新构图,改变边连接的两个点的关系
        for(int i=0;i<g.size();i++)
        {
            g[i].w-=inw[g[i].v];
            g[i].u=id[g[i].u];
            g[i].v=id[g[i].v];
        }
        n=idx-1;
        s=id[s];
    }
}

void solve()
{
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        g.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&xx[i],&yy[i]);
        }
        int a,b;
        double we;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            we=getdis(a,b);
            g.push_back(edge(a,b,we));
        }
        if(fun(1))
            printf("%.2lf\n",ans);
        else
            printf("poor snoopy\n");
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}