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
    double a,b,r,x,y,w,k,t,d,o,s,su;
    cin>>a>>b>>r>>x>>y>>w>>t;
    o=w*t;
    k=(y-b-r*sin(o))/(x-a-r*cos(o));
    d=sqrt(k*k+1);
    s=abs(k*a-b-k*x+y)/d;
    su=2*sqrt(r*r-s*s);
    printf("%.2lf\n",su);
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
