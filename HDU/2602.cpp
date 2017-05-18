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
const int maxn=1005;
const int maxm=100005; 

int c[maxn],w[maxn],dp[maxn];
int n,v;

void solve()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&v);
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=v;j>=c[i];j--)
				dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		printf("%d\n",dp[v]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

