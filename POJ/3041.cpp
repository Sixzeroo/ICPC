#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define in(a) scanf("%d",&a)

using namespace std;
const int maxn=510;

int g[maxn][maxn],matching[maxn],visit[maxn],n,k;

bool dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(!visit[i] && g[u][i])
        {
            visit[i]=1;
            if(matching[i]==-1 || dfs(matching[i]))
            {
                matching[i]=u;
                return true;  //只考虑一边
            }
        }
    }
    return false;
}

int hungry()
{
    int ans=0;
    memset(matching,-1,sizeof(matching));
    for(int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        if(dfs(i))
            ans++;
    }
    return  ans;
}

void solve()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        int a,b;
        memset(g,0,sizeof(g));
        for(int i=1;i<=k;i++)
        {
            in(a);
            in(b);
            g[a][b]=1;
        }
        printf("%d\n",hungry());
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}