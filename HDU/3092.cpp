#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int mod=1e9+7;
const int maxn=3005;
const int maxm=10005; 

bool is_prime[maxn];
int prime[maxn],num;
double dp[maxn];
ll ans[maxn];

void prime_init()
{
	num=0;
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<maxn;i++)
	{
		if(is_prime[i])prime[num++]=i;
		for(int j=0;j<num && i*prime[j]<maxn;j++)
		{
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0)break;  //保证每一个合数都被他的最小质因数排除
		}
	}
}


void solve()
{
	int S,M;
	prime_init();
	while(scanf("%d %d",&S,&M)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		fill(ans,ans+num,1);
		for(int i=0;i<num && prime[i]<S ;i++)
		{
			double tmp=log(prime[i]*1.0);
			for(ll j=S;j>=prime[i];j--)
				for(ll k=prime[i],q=1;k<=j;k*=prime[i],q++)  //可以重复，q表示重复次数
					if(dp[j-k]+q*tmp>dp[j])
					{
						dp[j]=dp[j-k]+q*tmp;
						ans[j]=ans[j-k]*k%M;
					}
		}
		printf("%lld\n",ans[S]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

