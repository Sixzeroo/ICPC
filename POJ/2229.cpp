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
const int MOD=1e9;
const int maxn=1000005;
const int maxm=10005; 

int dp[maxn];

void fun()
{
	int i;
	dp[1]=1,dp[2]=2;
	for(int i=3;i<=1e6;i++)
	{
		if(i&1) dp[i]=dp[i-1];
		else dp[i]=(dp[i-2]+dp[i/2])%MOD;
	}
}


void solve()
{
	int n;
	fun();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",dp[n]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
