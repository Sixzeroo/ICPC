#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

const  int MAX=100005;
int nums[MAX],sorted[MAX],root[MAX];
int cnt;  //记录主席树节点编号

struct segment
{
    int sum,l,r;
}tree[MAX<<5];

int creatnode(int sum,int l,int r)
{
    int ro=++cnt;
    tree[ro].sum=sum;
    tree[ro].l=l;
    tree[ro].r=r;
    return ro;
}

void Insert(int &ro,int pre,int pos,int l,int r)
{
    ro=creatnode(tree[pre].sum+1,tree[pre].l,tree[pre].r);
    if(l==r)return;
    int m=(l+r)>>1;
    if(pos<=m)
        Insert(tree[ro].l,tree[pre].l,pos,l,m);
    else
        Insert(tree[ro].r,tree[pre].r,pos,m+1,r);
}

int query(int S,int E,int l,int r,int k)
{
    if(l==r)return l;
    int sum_l=tree[tree[E].l].sum-tree[tree[S].l].sum;   //线段树中相同位置的结点的差值表示区间内的维护值
    int m=(l+r)>>1;
    if(k<=sum_l)
        return query(tree[S].l,tree[E].l,l,m,k);
    else
        return query(tree[S].r,tree[E].r,m+1,r,k-sum_l);
}

void solve()
{
    int n,m,num,pos;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        cnt=0;
        root[0]=0;    //一开始的线段树是一个空的线段树
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&nums[i]);
            sorted[i]=nums[i];
        }
        sort(sorted+1,sorted+1+n);
        num=unique(sorted+1,sorted+1+n)-(sorted+1);
        for(int i=1;i<=n;i++)
        {
            pos=lower_bound(sorted+1,sorted+1+num,nums[i])-sorted;
            Insert(root[i],root[i-1],pos,1,num);
        }
        int l,r,k;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&l,&r,&k);
            pos=query(root[l-1],root[r],1,num,k);
            printf("%d\n",sorted[pos]);
        }

    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
