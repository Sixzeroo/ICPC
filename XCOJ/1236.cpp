#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;



void solve()
{
    int a,b,c,d,i,j;
    cin>>a>>b>>c>>d;
    i=a*b;
    j=c*d;
    i=i>j?i-j:j-i;
    cout<<i<<endl;

}

int main()
{
    freopen("input.txt","r",stdin);
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}
