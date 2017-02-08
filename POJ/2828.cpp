#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_N 100005
#define SIZE 200005
#define in(a) scanf("%d",&a)
#define mm(a) memset(a,0,sizeof(a))
typedef long long ll;

#define lson l,m,k<<1
#define rson m+1,r,k<<1|1
#define mid (l+r)>>1

int ans[SIZE],temp[SIZE][2];

struct segtree
{
    int l,r,sum;   //sum记录区间内的空位数
}tree[SIZE<<2];

void pushup(int k)
{
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}

void build(int l,int r,int k)
{
    tree[k].l=l;
    tree[k].r=r;
    if(l==r)
    {
        tree[k].sum=1;
        return;
    }
    int m=mid;
    build(lson);
    build(rson);
    pushup(k);
}

int update(int pos,int k)  //根据所在的空位位置，返回最终的位置
{
    if(tree[k].l==tree[k].r)
    {
        tree[k].sum--;
        return tree[k].l;
    }
    int id;
    if(pos<=tree[k<<1].sum)    //根据空位定位位置再左子区间内
        id=update(pos,k<<1);
    else
    {
        pos-=tree[k<<1].sum;
        id=update(pos,k<<1|1);
    }
    pushup(k);
    return id;
}

void solve()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)    //输入插队时的位置
        {
            in(temp[i][0]);
            in(temp[i][1]);
        }
        build(1,n,1);
        for(int i=n;i>=1;i--)
        {
            ans[update(temp[i][0]+1,1)]=temp[i][1];     //位置要+1，不包括0
        }
        printf("%d",ans[1]);
        for(int i=2;i<=n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
}
