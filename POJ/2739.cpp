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
const int maxn=1005;
const int maxp=10005;
bool is_prime[maxp];
int prime[maxp],num;
int a[maxp];

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

void fun()
{
	memset(a,0,sizeof(a));
	int tmp;
	for(int i=0;i<num;i++)
		for(int j=i;j<num;j++)
		{
			tmp=0;
			for(int k=i;k<=j;k++)
				tmp+=prime[k];
			if(tmp<maxp)
				a[tmp]++;
		}
}



void solve()
{
	int t;
	init();
	fun();
	while(scanf("%d",&t)!=EOF && t)
	{
		printf("%d\n",a[t]);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
