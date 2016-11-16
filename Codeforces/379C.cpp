#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;
#define MAXSIZE 200005
#define in(a) scanf("%d",&a)

long long n,m,k,x,s;
long long a[MAXSIZE],b[MAXSIZE],c[MAXSIZE],d[MAXSIZE];

void solve()
{
    long long i;
    while(cin>>n>>m>>k)
    {
        cin>>x>>s;  // ˝æ› ‰»Î
        for(i=0;i<m;i++)
            cin>>a[i];
        for(i=0;i<m;i++)
            cin>>b[i];
        for(i=0;i<k;i++)
            cin>>c[i];
        for(i=0;i<k;i++)
            cin>>d[i];

        a[m]=x;
        b[m]=0;
        long long imin,o,e;
        imin=n*x;
        for(i=0;i<=m;i++)
        {
            o=s-b[i];
            if(o<0)
                continue;
            e=upper_bound(d,d+k,o)-d;
            if(e)
                imin=min(a[i]*(n-c[e-1]),imin);
            else
                imin=min(a[i]*n,imin);
        }
        cout<<imin<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
