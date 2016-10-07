#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;

#define mm(a,b) memset(a,b,sizeof(a))
#define LL long long

LL dist[105][105],man[105];
const LL INF=1000000000;
int n,p,c;

int dsum(int d)
{
    LL sum=0;
    for(int i=1;i<=n;i++)
        if(dist[d][man[i]]!=INF)
            sum+=dist[d][man[i]];
        else
            return -1;
    return sum;
}

void solve()
{
    int i,j,k,x,y,z;
    cin>>n>>p>>c;
    for(i=1;i<=n;i++)
        cin>>man[i];
    for(i=1;i<=p;i++)
        for(j=1;j<=p;j++)
            dist[i][j]=INF;
    for(i=1;i<=p;i++)
        dist[i][i]=0;
    for(i=0;i<c;i++)
    {
        cin>>x>>y>>z;
        dist[x][y]=dist[y][x]=z;
    }

    for(k=1;k<=p;k++)
        for(i=1;i<=p;i++)
            for(j=1;j<=p;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }

    LL rmin=INF;
    for(i=1;i<=p;i++)
    {
        j=dsum(i);
        if(j<rmin&&j!=-1)
            rmin=j;
    }
    cout<<rmin<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
