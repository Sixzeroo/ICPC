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

using namespace std;
#define INF 0x3f3f3f3f
#define SIZE 105

int n,m;
int edge[SIZE][SIZE];

void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
            }
}

void solve()
{
    int o,u,to,co,imax,imin,ii,ij;
    while(cin>>n)
    {
        if(n==0)
            break;
        memset(edge,INF,sizeof(edge));
        for(int i=0;i<n;i++)
            edge[i][i]=0;
        for(int i=0;i<n;i++)
        {
            cin>>u;
            for(int j=0;j<u;j++)
            {
                cin>>to>>co;
                edge[i][to-1]=co;
            }
        }
        floyd();
        imin=INF;
        ii=-1;

        for(int i=0;i<n;i++)
        {
            imax=0;
            for(int j=0;j<n;j++)
                imax=max(imax,edge[i][j]);   //一个结点到其他结点的最大值
            if(imax<imin)
            {
                ii=i;
                imin=imax;
            }
        }
        cout<<ii+1<<" "<<imin<<endl;    //存储编号与实际编号转换
    }

}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
