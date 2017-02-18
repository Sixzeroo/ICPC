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

#define INF 0x3f3f3f3f
#define in(a) scanf("%d",&a)
#define out(a) printf("%d",a)

int a[1005];

void solve()
{
    int m;
    while(in(m)!=EOF)
    {
        if(m==0)
            break;
        for(int i=0;i<m;i++)
            in(a[i]);
        int roc=a[0];
        for(int i=1;i<m;i++)
            roc^=a[i];
        int ans=0;
        for(int i=0;i<m;i++)
            if(a[i]>(roc^a[i]))
                ans++;
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
