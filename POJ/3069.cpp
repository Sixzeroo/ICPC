#include<stdio.h>
#include<iostream>
#include<sstream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int a[1005];
int n,r,ans;

void solve()
{
    int i,k;
    while(cin>>r>>n)
    {
        if(r==-1&&n==-1)
            break;
        ans=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        i=0;
        while(i<n)
        {
            k=a[i++];
            while(i<n&&a[i]<=k+r)
                i++;
            int p=a[i-1];
            while(i<n&&a[i]<=p+r)   //要考虑标记点两边的情况
                i++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
