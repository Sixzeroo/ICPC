#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<utility>
#include<map>

using namespace std;

void solve()
{
    int u,n,a[50],i,j,m,y;
    cin>>u;
    while(u--)
    {
        cin>>n;
        fill(a,a+2*n,1);
        for(i=0;i<n;i++)
        {
            cin>>m;
            a[m+i]=-1;
        }
        m=0;
        while(m<2*n)   //向前遍历
        {
            if(a[m]<0)
            {
                j=m;
                y=0;
                while(j--)   //向后检查
                {
                    if(a[j]==1)
                    {
                        cout<<y+1<<" ";
                        a[j]=0;
                        break;
                    }
                    if(a[j]==-1)y++;   //记录右括号数量
                }
            }
            m++;
        }
        cout<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
