#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;
#define MAXSIZE 100005
#define in(a) scanf("%d",&a)

void solve()
{
    int a,b,c,d,j;
    long long ans;
    while(cin>>a>>b>>c>>d)
    {
        ans=0;
        j=min(a,min(c,d));
        ans+=256*j;
        a-=j;
        j=min(a,b);
        ans+=32*j;
        cout<<ans<<endl;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}