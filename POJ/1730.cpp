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
const ll maxn=100003;
const ll maxp=100003;
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

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

void solve()
{
	ll x;
	prime_init();
	while(scanf("%lld",&x)!=EOF && x)
	{
		ll ans=-1,i=0,tmp;
		bool flag=0;
		if(x<0)
			x=-x,flag=1;
		while(x!=1 && i<num-1)
		{
			tmp=0;
			while(x%prime[i]==0)
			{
				tmp++;
				x/=prime[i];
			}
			i++;
			ans=ans==-1?tmp:gcd(ans,tmp);
		}
		if(x!=1) ans=1;
		if(flag)      //如果是负数的话将ans变为奇数
			while(ans%2==0)
				ans/=2;
		printf("%lld\n",ans);
	}
}

int main()
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
