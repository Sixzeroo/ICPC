#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define in(a) scanf("%d",&a)

using namespace std;
const int maxn=603;


vector <int> G[maxn];
int visit[maxn],matching[maxn];
int n,p,m;

bool dfs(int u)
{
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!visit[v])
        {
            visit[v]=1;
            if(matching[v]==-1 || dfs(matching[v]))
            {
                matching[v]=u;
                matching[v]=u;
                return true;         //新建匹配
            }
        }
    }
    return false;
}

int hungury()
{
    int ans=0;
    memset(matching,-1, sizeof(matching));
    for(int i=1;i<=p;i++)
    {
        if(matching[i]==-1)
        {
            memset(visit,0, sizeof(visit));
            if(dfs(i))
                ans++;
        }
    }
    return ans;
}


void solve()
{
    int t;
    in(t);
    while (t--)
    {
        in(p);
        in(n);
        m=p+n;
        for(int i=1;i<=p;i++)
        {
            int tem,stu;
            in(tem);
            for(int j=0;j<tem;j++)
            {
                in(stu);
                stu+=p;       //标号
                G[i].push_back(stu);
                G[stu].push_back(i);     //建图
            }
        }
        //输入部分结束
        int ans=hungury();
        if(ans==p)
            printf("YES\n");
        else
            printf("NO\n");
        for(int i=0;i<=m;i++)
            G[i].clear();     //清空数据
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}