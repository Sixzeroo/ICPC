#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstring>
#include<cmath>
using namespace std;

#define SIZE 1000005
#define mm(a,b) memset(a,b,sizeof(a))

int a[SIZE],b[SIZE],anse[SIZE/10+5];

void solve()
{
    int n,q,i,d,t,ml=0;
    mm(a,0);
    mm(b,0);
    scanf("%d%d",&n,&q);
    //cin>>n>>q;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&d,&t);
        //cin>>d>>t;
        a[d]++;
        a[t]--;
        ml=max(ml,t);
    }
    int num=1,ans;
    b[0]=1;
    for(i=1;i<=ml+1;i++)  //+1确保从空区间开始空区间结束
    {
        a[i]+=a[i-1];
        b[i]=num;
        if(a[i]==0&&a[i-1]!=0)num++; //下一个在空区间内的点归入下一个大区间
    }
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&d,&t);
        //cin>>d>>t;
        if(t>ml)t=ml+1;
        if(d>ml)d=ml+1;
        ans=b[t]-b[d];
        if((d>0&&a[d]==0&&a[d-1]==0)||(d==0&&a[d]==0))  //对开始为空区间的情况进行讨论
            ans++;
        anse[i]=ans;
        //cout<<ans<<endl;
    }
    for(i=0;i<q;i++)
        printf("%d\n",anse[i]);
        //cout<<anse[i]<<endl;
    printf("\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    //cin>>t;
    while(t--)solve();
    return 0;
}
