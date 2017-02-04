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
#define in(a) scanf("%d",&a)
#define out(a) printf("%d",a)
typedef long long ll;

#define SIZE 50005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

//Ïß¶ÎÊ÷»ù´¡Ìâ
int SUM[SIZE<<2];

void pushup(int rt)
{
    SUM[rt]=SUM[rt<<1]+SUM[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&SUM[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update1(int p,int tem,int l,int r,int rt)
{
    if(l==r)
    {
        SUM[rt]+=tem;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update1(p,tem,lson);
    else update1(p,tem,rson);
    pushup(rt);
}

void update2(int p,int tem,int l,int r,int rt)
{
    if(l==r)
    {
        SUM[rt]-=tem;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update2(p,tem,lson);
    else update2(p,tem,rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        return SUM[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(m<R) ret+=query(L,R,rson);
    return ret;
}

void solve()
{
    int t,n,x,y;
    string ch;
    scanf("%d",&t);
    for(int id=1;id<=t;id++)
    {
        printf("Case %d:\n",id);
        in(n);
        build(1,n,1);
        while(cin>>ch)
        {
            if(ch=="End")
                break;
            else if(ch=="Add")
            {
                in(x);
                in(y);
                update1(x,y,1,n,1);
            }
            else if(ch=="Sub")
            {
                in(x);
                in(y);
                update2(x,y,1,n,1);
            }
            else
            {
                in(x);
                in(y);
                printf("%d\n",query(x,y,1,n,1));
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
