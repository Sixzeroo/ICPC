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
const int MOD=1000000;
const int maxn=1005;
const int maxm=10005; 

int A,S;
int a[maxn],dp[maxn][maxm];  //dp[i+1][j]  表示从i种物品中取出j个的组合数
int T,B;   //T表示种类数，B表示取得数目

void fun()
{
	for(int i=1; i<=T+1; ++i) dp[i][0] = 1; // 一个都不取
	for(int i=1; i<=T; ++i) {
		for(int j=1; j<=B; ++j) {
			if(j-1-a[i] >= 0)
				dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]] + MOD) % MOD;
			else
				dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % MOD;
		}
	}
}

void solve()
{
	while(scanf("%d %d %d %d",&T,&A,&S,&B)!=EOF)
	{
		int tmp;
		for(int i=1;i<=A;i++)
		{
			scanf("%d",&tmp);
			a[tmp]++;
		}
		fun();
		int ans=0;
		for(int i=S;i<=B;i++) ans=(ans+dp[T+1][i])%MOD;
		printf("%d\n",ans);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

