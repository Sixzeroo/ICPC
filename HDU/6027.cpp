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
const int maxn=100010;
const int maxm=100005; 

ll quick_mod(ll a,ll b,ll c)
{
	ll ans=1;
	while(b>0)
	{
		if(b&1) ans=(ans*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return ans;
}

void solve()
{
	int t;
	scanf("%d",&t);
	int n,k;
	while(t--)
	{
		scanf("%d %d",&n,&k);
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=quick_mod(i,k,mod);
		ans=ans%mod;
		printf("%lld\n",ans);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

