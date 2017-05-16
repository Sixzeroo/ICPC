#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=100005;
const int maxm=100005; 

void solve()
{
	ll x;
	while(scanf("%lld",&x)!=EOF)
	{
		int ans=0;
		for(int i=2;i*i<=2*x;i++)
		{
			if((2*x)%i) continue;
			int tmp=2*x/i+1-i;
			if(tmp%2) continue;
			ans++;
		}
		printf("%d\n",ans);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
