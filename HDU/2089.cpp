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

#define SIZE 305
#define INF 0x3f3f3f3f
#define in(a) scanf("%d",&a)
typedef long long ll;
#define MAX_V 50005
#define MAX_E 10005

ll dp[25][3];
int digit[25];

ll dfs(int pos,int status,int limit)
{
    if(pos<=0)
        return status!=2;
    if(!limit && dp[pos][status]!=-1)   //记录之前的结果 直接返回
        return dp[pos][status];
    ll ans=0;
    int End = limit?digit[pos]:9;   //确定上限
    for(int i=0;i <= End; i++)
    {
        int nstatus = status;   //要设置初始值
        if(i == 4)
            nstatus = 2;
        else if(status==0 && i==6)
            nstatus = 1;
        else if(status==1 && i!=2 && i!=6)
            nstatus = 0;
        else if(status==1 && i==2)
            nstatus = 2;
        ans+=dfs(pos-1,nstatus,limit && i==End);
    }
    if(!limit)
        dp[pos][status]=ans;
    return ans;
}

int cal(ll x)
{
    int cnt = 0;
    while(x)
    {
        digit[++cnt] = x%10;
        x/=10;
    }
    digit[cnt+1] = 0;
    return cnt;
}

int solve()
{
    ll n,m;
    memset(dp,-1,sizeof(dp));
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;    //结束标志
        int lenn=cal(n-1);
        ll resn=dfs(lenn,0,1);

        int lenm=cal(m);
        ll resm=dfs(lenm,0,1);
        printf("%ld",resm-resn);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
