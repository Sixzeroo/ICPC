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
    int n;
    while(cin>>n)
    {
        ll res=1,x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x%2==1)
                res*=x;
        }
        cout<<res<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
}
