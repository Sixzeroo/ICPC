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

#define SIZE_V 10005
#define INF 0x3f3f3f3f

int edge[SIZE_V][SIZE_V];
int V;
int d[SIZE_V];
int used[SIZE_V];


int prim()
{
    long long res=0;
    fill(d,d+V,INF);
    fill(used,used+V,false);
    d[0]=0;
    while(1)
    {
        int v=-1;
        for(int i=0;i<V;i++)
            if(!used[i]&&(v==-1||d[v]>d[i]))v=i;
        if(v==-1)break;
        used[v]=true;
        res+=d[v];
        for(int i=0;i<V;i++)
            if(!used[i]&&d[i]>edge[v][i])
                d[i]=edge[v][i];
    }
    return res;
}

void solve()
{
    while(cin>>V)
    {
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                cin>>edge[i][j];
        long long  res=prim();
        cout<<res<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
