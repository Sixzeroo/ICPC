#include <iostream>
#include<queue>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;


void solve()
{
    char s[10003];
    int n,m,i,j,l;
    scanf("%d%d",&n,&m);
    while(n--)
    {
        j=0;
        scanf("%s",s);
        l=strlen(s);
        for(i=0;i<l;i++)
            j+=abs(s[i]-s[l-i-1]);
        if(j<=m)
            printf("%s %d",s,j);
        if(n)
            printf("\n");
    }

}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
