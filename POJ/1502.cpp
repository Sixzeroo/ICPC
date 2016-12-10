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
#define SIZE 105

int edge[SIZE][SIZE];
int V,E;
int di[SIZE];
int used[SIZE];

void dij(int s)
{
    fill(di,di+V,INF);
    fill(used,used+V,false);
    di[s]=0;

    while(1)
    {
        int v=-1;
        for(int i=0;i<V;i++)
        {
            if(!used[i]&&(v==-1||di[i]<di[v]))
                v=i;
        }
        if(v==-1)
            break;
        used[v]=true;
        for(int i=0;i<V;i++)
            di[i]=min(di[i],edge[v][i]+di[v]);
    }
}

int into_int(string st)
{
    int d;
    stringstream t;
    t<<st;
    t>>d;
    return d;
}

void solve()
{
    string x;
    while(cin>>V)
    {
        memset(edge,INF,sizeof(edge));
        for(int i=0;i<V;i++)
            edge[i][i]=0;
        for(int i=0;i<V;i++)
            for(int j=0;j<i;j++)
            {
                cin>>x;
                if(x[0]=='x')
                    edge[i][j]=edge[j][i]=INF;
                else
                    edge[i][j]=edge[j][i]=into_int(x);
            }
        dij(0);
        int imin=0;
        for(int i=1;i<V;i++)
            imin=max(di[i],imin);    //取所有点到0点的最短路径的最大值
        cout<<imin<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
