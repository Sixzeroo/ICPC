#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100005;
typedef long long ll;

struct segnode
{
    int lt,rt,lv,rv;     //左右孩子结点的位置，维护的区间值
    ll sum,lazy;      //lazy思想，在查询的时候再进行修改
}tree[maxn<<4];

int cnt,now,a[maxn],root[maxn];

void build(int &id,int l,int r)
{
    tree[++cnt]=tree[id];
    id=cnt;
    tree[id].lv=l;
    tree[id].rv=r;
    if(l==r)
    {
        tree[id].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(tree[id].lt,l,mid);   //引用的妙处
    build(tree[id].rt,mid+1,r);
    tree[id].sum=tree[tree[id].lt].sum+tree[tree[id].rt].sum;
    return;
}

void update(int &id,int l,int r,int v)
{
    tree[++cnt]=tree[id];
    id=cnt;
    tree[id].sum+=(min(r,tree[id].rv)-max(l,tree[id].lv)+1)*v;
    if(l<=tree[id].lv && tree[id].rv<=r)
    {
        if(tree[id].lv!=tree[id].rv)
            tree[id].lazy+=v;
        return;
    }
    int mid=(tree[id].lv+tree[id].rv)>>1;
    if(r<=mid)
        update(tree[id].lt,l,r,v);    //引用的妙用
    else if(l>mid)
        update(tree[id].rt,l,r,v);
    else
    {
        update(tree[id].lt,l,r,v);
        update(tree[id].rt,l,r,v);
    }

}

ll query(int id,int l,int r)
{
    if(l<=tree[id].lv && tree[id].rv<=r)
        return tree[id].sum;
    ll ret=(min(r,tree[id].rv)-max(l,tree[id].lv)+1)*tree[id].lazy;
    int mid=(tree[id].lv+tree[id].rv)>>1;
    if(r<=mid)
        ret+=query(tree[id].lt,l,r);
    else if(l>mid)
        ret+=query(tree[id].rt,l,r);
    else
        ret+=query(tree[id].lt,l,r)+query(tree[id].rt,l,r);
    return ret;
}

void solve()
{
    int n,m,l,r,t,d;
    char op;
    bool hh=0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(hh)
            printf("\n");
        else
            hh=1;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        now=cnt=0;
        build(root[0],1,n);
        for(int i=0;i<m;i++)
        {
            scanf(" %c",&op);    //注意前面要加一个空格
            if(op=='C')
            {
                now++; //时间增加
                scanf("%d %d %d",&l,&r,&d);
                update(root[now]=root[now-1],l,r,d);
            }
            if(op=='Q')
            {
                scanf("%d %d",&l,&r);
                printf("%lld\n",query(root[now],l,r));
            }
            if(op=='H')
            {
                scanf("%d %d %d",&l,&r,&t);
                printf("%lld\n",query(root[t],l,r));
            }
            if(op=='B')
            {
                scanf("%d",&now);
                cnt=root[now+1]-1;   //释放结点
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
