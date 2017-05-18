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
const int maxm=10005; 

int a[maxn], dp[maxn]; // a为序列， dp[i]为以a[i]为结尾的最长上升子序列长度

int LIS(int n)
{
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;i++)
	{
        *lower_bound(dp,dp+i,a[i])=a[i];
	}
	return lower_bound(dp,dp+n,INF)-dp;
}


void solve()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",LIS(n));
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

