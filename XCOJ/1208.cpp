#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<sstream>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<algorithm>
#include<set>
#include<functional>
#include<stack>
#include<iterator>
using namespace std;


typedef struct statu
{
    double g[5][5];
}sta;

sta mul(sta a,sta b)
{
    sta c;
    int i,j,k;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            c.g[i][j]=0;
            for(k=0;k<5;k++)
                c.g[i][j]+=a.g[i][k]*b.g[k][j];    //i到j有多条线路
        }
    }
    return c;
}

sta pow(sta a,int d)   //利用二进制数的特点
{
    sta b,c;
    b=a;
    memset(c.g,0,sizeof(c.g));
    for(int i=0;i<5;i++)
        c.g[i][i]=1;     //累加位初始化
    while(d)
    {
        if(d&1)c=mul(c,b);   //累加位
        b=mul(b,b);    //二进制增长位
        d/=2;
    }
    return c;
}

void solve()
{
    int n,s,maxj;
    double maxi=0;
    cin>>n;
    int i,j;
    sta a,ans;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>a.g[j][i];     //j在前使其与前面的运算对应
    cin>>s;
    if(n==1)
    {
        cout<<s<<endl;
        return;
    }
    ans=pow(a,n-1);
    //for(i=0;i<5;i++)    //已经确定起点
        for(j=4;j>=0;j--)    //不能使用for(j=0;j<5;j++),原因：概率相同要选最小的，多次乘法运算时不精确的，通过1e-6来获得近似精确的解
            if(ans.g[s-1][j]>maxi||abs(ans.g[s-1][j]-maxi)<1e-6)
            {
                maxi=ans.g[s-1][j];
                maxj=j;
            }
    cout<<maxj+1<<endl;
    return;
}



int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
