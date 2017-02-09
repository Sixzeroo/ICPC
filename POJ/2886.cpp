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

#define SIZE 500005
#define lson l,m,k<<1
#define rson m+1,r,k<<1|1
#define mid (l+r)>>1

char name[SIZE][15];
int val[SIZE];
int factor_table[SIZE];

void init_factor_table(int n)
{
	fill(factor_table, factor_table + n + 1, 1);
	for (int i = 2; i <= n; ++i)
	{
		if (factor_table[i] == 1)   //从最小的素数开始计算
		{
			for (int j = i; j <= n; j += i)
			{
				int k = 0;
				for (int m = j; m % i == 0; m /= i, ++k);     //确定当前i的指数
				factor_table[j] *= k + 1;
			}
		}
	}
}

struct segtree
{
    int l,r,sum;
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

int id;

void update(int pos,int k)  //根据当前位置确定最终属于的位置
{
    if(tree[k].l==tree[k].r)
    {
        id=tree[k].l;
        tree[k].sum--;
        return;
    }
    if(pos<=tree[k<<1].sum)
        update(pos,k<<1);
    else
    {
        pos-=tree[k<<1].sum;
        update(pos,k<<1|1);
    }
    pushup(k);
}

void solve()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        init_factor_table(n);
        build(1,n,1);
        for(int i=1;i<=n;i++)
            scanf("%s%d",name[i],&val[i]);
        //确定因子数最大的数
        int maxn=0,maxv=-1;
        for(int i=1;i<=n;i++)
        {
            if(factor_table[i]>maxv)
            {
                maxn=i;
                maxv=factor_table[i];
            }
        }

        id=0;
        val[id]=0;
        for(int i=1;i<=maxn;i++)   //模拟过程
        {
            if(val[id]>0)   //确定下一个人所在的位置
                k=((k+val[id]-2)%n+n)%n+1;
            else
                k=((k+val[id]-1)%n+n)%n+1;
            update(k,1);
            //cout<<k<<" "<<name[id]<<endl;
            n--;  //规模减小
        }
        printf("%s %d\n",name[id],maxv);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
