#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn=2005;
const int maxm=100005;
int pre[maxn];
int n,m;

struct edge
{
	int u,v,w;
}es[maxm];

void init()
{
	for(int i=1;i<=n;i++)
		pre[i]=i;
}

int find(int x)
{
	if(pre[x]==x) return x;
	else
		return pre[x]=find(pre[x]);
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	pre[x]=y;
}

bool comp(const edge& e1,const edge & e2)
{
	return e1.w<e2.w;
}

int Krustral()
{
	sort(es,es+m,comp);    //从小到大排序
	/*for(int i=0;i<m;i++)
		cout<<es[i].u<<" "<<es[i].v<<" "<<es[i].w<<endl;*/
	init();
	int ret=0;
	for(int i=0;i<m;i++)
	{
		edge e=es[i];
		if(find(e.u)!=find(e.v))
		{
			unite(e.u,e.v);
			//cout<<e.u<<" "<<e.v<<" "<<e.w<<endl;
			ret+=e.w;
		}
	}
	return ret;
}

void solve()
{
	while(scanf("%d",&n)!=EOF && n)
	{
		m=n*(n-1)/2;
		for(int i=0;i<m;i++)
		{
            scanf("%d %d %d",&es[i].u,&es[i].v,&es[i].w);
		}
		int ans=Krustral();
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
