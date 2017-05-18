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

int digit[30];
ll dp[30][2];   //digit存储数字，dp存储状态的记忆化数组(注意范围)

ll dfs(int l,bool fo,bool jud)
{
	if(l==0) return 1;    //l是0还是-1取决于怎样存储数
	if(!jud && dp[l][fo]!=-1) return dp[l][fo];   //排除上界的前缀情况
	int len=jud?digit[l]:9;
	ll tmp=0;
	for(int i=0;i<=len;i++)
	{
		if(i==9 && fo)continue;
		tmp+=dfs(l-1,i==4,jud&&i==len);
	}
	if(!jud) dp[l][fo]=tmp;     //排除上界前缀和的情况
	return tmp;
}

ll fun(ll k)
{
	int pos=0;
	while(k)
	{
		digit[++pos]=k%10;
		k/=10;
	}
	ll ans=dfs(pos,false,true);
	return ans; //不包括0
}


void solve()
{
	int t;
	ll n;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));    //dp数组初始化放在全局中，达到复用的目的
	while(t--)
	{
		scanf("%lld",&n);
        ll ans=n-fun(n)+1;
		printf("%lld\n",ans);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

