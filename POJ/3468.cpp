#include <iostream>
#include <cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
#include<map>

#define in(a) scanf("%d",&a)

using namespace std;
int const SIZE=1e5+5;
#define INF 0x3f3f3f3f
#define ll long long

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

ll sum[SIZE<<2],lazy[SIZE<<2];

void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int ln,int rn,int rt)
{
    if(lazy[rt])
    {
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        sum[rt<<1]+=(ll)ln*lazy[rt];
        sum[rt<<1|1]+=(ll)rn*lazy[rt];
        lazy[rt]=0;
    }
    return;
}

void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
    return;
}

void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        lazy[rt]+=c;
        sum[rt]+=(r-l+1)*c;
        return;
    }
    int m=(l+r)>>1;
    pushdown(m-l+1,r-m,rt);
    if(L<=m) update(L,R,c,lson);
    if(m<R) update(L,R,c,rson);
    pushup(rt);
    return;
}

ll quert(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    pushdown(m-l+1,r-m,rt);
    ll ret=0;
    if(L<=m) ret+=quert(L,R,lson);
    if(m<R) ret+=quert(L,R,rson);
    return ret;
}

void solve()
{
    int n,q,a,b;
    ll c;
    char s[2];
    in(n);
    in(q);
    build(1,n,1);
    for(int i=0;i<q;i++)
    {
        scanf("%s",s);
        if(s[0]=='C')
        {
            in(a);
            in(b);
            in(c);
            update(a,b,c,1,n,1);
        }
        else
        {
            in(a);
            in(b);
            printf("%lld\n",quert(a,b,1,n,1));
        }
    }
}



int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
