#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>
#include<utility>

using namespace std;

pair<int,int> p[1003];

void solve()
{
    int n,i,m,d;
    double sum,ans;
    while(cin>>n)
    {
        sum=0;
        for(i=0;i<n;i++)
            cin>>p[i].first>>p[i].second;
        sort(p,p+n);
        sum+=p[0].second;
        d=p[0].first+p[0].second;
        for(i=1;i<n;i++)
        {
            d=max(d,p[i].first);   //处理一个进程之前机器空闲的情况
            m=d-p[i].first+p[i].second;
            sum+=m;
            d+=p[i].second;
        }
            //sum+=(p[i].second+p[i-1].second+p[i].first-p[i-1].first);
        ans=sum/n;
        printf("%.4lf\n",ans);
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
