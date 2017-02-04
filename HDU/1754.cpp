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
typedef long long ll;

#define SIZE 200005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

//Ïß¶ÎÊ÷»ù´¡Ìâ
int MAX[SIZE<<2];

void pushup(int rt)
{
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&MAX[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p,int tem,int l,int r,int rt)
{
    if(l==r)
    {
        MAX[rt]=tem;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,tem,lson);
    else update(p,tem,rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        return MAX[rt];
    }
    int m=(l+r)>>1;
    int ret=-1;
    if(L<=m) ret=max(query(L,R,lson),ret);
    if(m<R) ret=max(query(L,R,rson),ret);
    return ret;
}

void solve()
{
    int n,m;
    char ch;
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        for(int i=0;i<m;i++)
        {
            cin>>ch;
            if(ch=='U')
            {
                scanf("%d%d",&a,&b);
                update(a,b,1,n,1);
            }
            else
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(a,b,1,n,1));
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
