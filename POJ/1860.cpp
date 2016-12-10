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

#define SIZE_V 105

typedef struct ee
{
    int to,fo;
    double bi,sh;  //比率以及手续费
}pa;
int n,m,s;
double v;
double d[SIZE_V];
pa edge[2*SIZE_V];

bool find_loop()
{
    memset(d,0,sizeof(d));
    d[s]=v;

    for(int i=1;i<=n;i++)
        for(int j=0;j<2*m;j++)
        {
            pa e=edge[j];
            if(d[e.to]<(d[e.fo]-e.sh)*e.bi)
            {
                d[e.to]=(d[e.fo]-e.sh)*e.bi;
                if(i==n)
                    return true;
            }
        }
    return false;
}

void solve()
{
    int x,y;
    double h,t;
    while(cin>>n>>m>>s>>v)
    {
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            cin>>h>>t;
            edge[2*i].fo=x;
            edge[2*i].to=y;
            edge[2*i].sh=t;
            edge[2*i].bi=h;
            cin>>h>>t;
            edge[2*i+1].fo=y;
            edge[2*i+1].to=x;
            edge[2*i+1].sh=t;
            edge[2*i+1].bi=h;
        }
        fill(d,d+n,0);
        d[1]=v;
        if(find_loop())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
