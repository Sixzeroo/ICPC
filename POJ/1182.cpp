#include <iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;

#define MAXN 500005
#define in(a) scanf("%d",&a)

int fa[MAXN];
int rm[MAXN];


void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		rm[i]=0;
	}
}

int find(int x)
{
	if(x==fa[x])
		return x;

	int t=fa[x];
	fa[x]=find(fa[x]);
	rm[x]=(rm[x]+rm[t])%3;
	return fa[x];
}

void Union(int x,int y,int d)
{
	int fx=find(x);
	int fy=find(y);

	fa[fy]=fx;
	rm[fy]=(3-rm[y]+d-1+rm[x])%3;
}



void solve()
{
	int n,k,d,x,y;
	int ans=0;
    in(n);
    in(k);
	init(n);
	for(int i=0;i<k;i++)
	{
	    in(d);
	    in(x);
	    in(y);
		if(x>n || y>n || (d==2 && x==y)) ans++;
		else if(find(x) == find (y))
		{
			if(d==1 && rm[x]!=rm[y]) ans++;
			if(d==2 && (rm[x]+1)%3 != rm[y]) ans++;
		}
		else Union(x,y,d);
	}
	printf("%d\n",ans);
}



int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

