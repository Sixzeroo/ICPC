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
const int maxn=10;
const int maxm=20000*6 + 5; 

int a[maxn],m[maxn],dp[maxm];    //a表示数，m表示数的个数，dp范围是所有数的和的范围

bool fun(int n,int K) //n表示数字种类,K表示组成的和
{
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i=1; i<=n; ++i) {    //根据存储方式作出改变
		for(int j=0; j<=K; ++j) {
			if(dp[j] >= 0) dp[j] = m[i]; // 前i-1个数已经能凑成j了
			else if(j < a[i] || dp[j-a[i]] <= 0) dp[j] = -1; // 否则，凑不成j或者a[i]已经用完，则无法满足
			else dp[j] = dp[j-a[i]] - 1; // 否则可以凑成
		}
	}
	return dp[K]>=0;   
}

void solve()
{
	for(int i=0;i<=6;i++) a[i]=i;
	int id=0;
	while(1)
	{
		int tot=0,tmp;
		for(int i=1;i<=6;i++)
		{
			scanf("%d",&m[i]);
			tot+=m[i]*i;
		}
		if(tot==0) break;
		id++;
		bool ans=fun(6,tot/2);
		if(tot&1 || !ans) printf("Collection #%d:\nCan't be divided.\n\n",id);
		else printf("Collection #%d:\nCan be divided.\n\n",id);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

