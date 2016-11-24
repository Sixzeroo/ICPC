#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;
typedef long long ll;

ll a[100005],b[100005];

void solve()
{
    int n,m;
    while(cin>>n>>m)
    {
        ll res=1e10;
        for(int i=0;i<m;i++)
        {
            cin>>a[i]>>b[i];
            res=min(res,b[i]-a[i]+1);     //取最小的mex值
        }
        cout<<res<<endl;
        int tem=0;
        while(n--)
        {
            cout<<tem<<" ";
            tem++;
            if(tem==res)
                tem=0;
        }
    }
    return;
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
