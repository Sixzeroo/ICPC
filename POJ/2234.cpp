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

int a[25];

void solve()
{
    int m;
    while(in(m)!=EOF)
    {
        int b,c;
        in(b);
        for(int i=1;i<m;i++)
        {
            in(c);
            b^=c;
        }
        if(b)printf("Yes\n");
        else
            printf("No\n");
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
