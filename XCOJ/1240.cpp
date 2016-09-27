#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;

int e[1005],f[1005],g[1005];

void solve()
{
   long long n,t,i,ans=0;
   cin>>n;
   for(i=0;i<n;i++)
    {
        cin>>e[i]>>f[i]>>g[i];
        e[i]=e[i]-g[i];
    }
    cin>>t;
    sort(e,e+n);
    i=0;
    for(i=0;i<n;i++)
        t-=g[i];
    if(t<0)
    {
        cout<<"Oh,my god!"<<endl;
        return;
    }
    for(i=0;i<n;i++)
    {
        t-=e[i];
        if(t<0)
            break;
        ans++;
    }
    cout<<ans<<endl;
    return;

}

int main()
{
    freopen("input.txt","r",stdin);
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
