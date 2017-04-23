#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
#define INF 0x3f3f3f3f
const int maxn=100005;
const int maxp=32768;
bool is_prime[maxp];
int prime[maxp],num;

void init()
{
	num=0;
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<maxp;i++)
	{
		if(is_prime[i]) prime[num++]=i;
		for(int j=0;j<num && i*prime[j]<maxp;j++)
		{
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}

void fun(int a)
{
	int p1[maxp],p2[maxp];
	int t=0,u,i=0;
	while(a!=1)
	{
		u=0;
		while(a%prime[i]==0)
		{
			p1[t]=prime[i];
			u++;
			a/=prime[i];
		}
		if(u) p2[t++]=u;
		i++;
	}
	for(int i=t-1;i>=0;i--)
	{
		if(i!=t-1) printf(" ");
		printf("%d %d",p1[i],p2[i]);
	}
    printf("\n");
}

void solve()
{
	int a,b;
	char ch;
	int tt;
    init();
	while(scanf("%d",&a)!=EOF && a)
	{
		tt=1;
		scanf("%d%c",&b,&ch);
        tt=pow(a,b);
		while(ch!='\n')
		{
			scanf("%d%d%c",&a,&b,&ch);
			tt*=pow(a,b);
		}
		fun(tt-1);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
