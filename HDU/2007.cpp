#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_N 100005
#define in(a) scanf("%d",&a)
#define ll long long
#define mm(a) memset(a,0,sizeof(a))


void solve()
{
    int resj,reso;
    int x,y;
    while(cin>>x>>y)
    {
        if(x>y)
            swap(x,y);
        resj=0;
        reso=0;
        for(int i=x;i<=y;i++)
        {
            if(i%2==0)
                reso=reso+i*i;
            else
                resj=resj+i*i*i;
        }
        cout<<reso<<" "<<resj<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
}
