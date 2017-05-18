#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=105;
const int maxm=100005; 
int ans[maxn];

struct node
{
	int v,u,id;
}a[maxn];

bool Cmp1(const node &a,const node &b)
{
	return a.v<b.v;
}
bool Cmp2(const node &a,const node &b)
{
	return a.id<b.id;
}

void solve()
{
	int n,w;
	int sum;
	while(cin>>n>>w)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].v;
			a[i].id=i;
			sum+=a[i].v;
		}
		double rate=1.0*w/sum;
		if(rate<0.5) 
		{
			cout<<"-1"<<endl;
			continue;
		}
		int last=w,tmp;
		bool endflag=0;
		sort(a+1,a+n+1,Cmp1);
		for(int i=1;i<=n;i++)
		{
			tmp=floor(a[i].v*rate);
			if(2*tmp<a[i].v) tmp++; //防止在一半以下
            a[i].u=tmp;
			last-=a[i].u;
			if(last<0) endflag=1;
		}
		if(endflag)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=n;last>0;i--)
		{
			tmp=a[i].v-a[i].u;
			if(last>=tmp) 
			{
				last-=tmp;
				a[i].u=a[i].v;
			}
			else
			{
                a[i].u+=last;
				last=0;
			}
		}
		sort(a+1,a+n+1,Cmp2);
		for(int i=1;i<=n;i++)
			cout<<a[i].u<<" ";
		cout<<endl;
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}

