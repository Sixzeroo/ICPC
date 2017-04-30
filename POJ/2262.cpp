#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <utility>

using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
const int maxn=1000003;
const int maxp=1000003;
bool is_prime[maxp];
int prime[maxp],num;

void prime_init()
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

void solve()
{
	ll x;
	prime_init();
	while(scanf("%lld",&x)!=EOF && x)
	{
		bool flag=1;
		for(ll i=1;i<=x-i;i++)
			if(is_prime[i] && is_prime[x-i])
			{
				printf("%lld = %lld + %lld\n",x,i,x-i);
				flag=0;
				break;
			}
		if(flag)
			printf("Goldbach's conjecture is wrong.\n");
	}
}

int main()
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
