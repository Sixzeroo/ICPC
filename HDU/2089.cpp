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

int digit[10],dp[10][2],visit[10][2];   //digit存储数字，dp存储状态的记忆化数组，visit访问标记

int dfs(int l,bool six,bool jud)
{
	if(l==0) return 1;    //搜索结束的状态
	if(!jud && visit[l][six]) return dp[l][six];
	int len=jud ? digit[l]:9;
	int tmp=0;
	for(int i=0;i<=len;i++)
	{
		if(i==4 || (six && i==2)) continue;
		tmp+=dfs(l-1,i==6,jud&&(i==len));
	}
	if(!jud)
	{
		visit[l][six]=1;
		dp[l][six]=tmp;
	}
	return tmp;
}

int fun(int k)
{
	memset(dp,0,sizeof(dp));
	memset(visit,0,sizeof(visit));
	int pos=0;
	while(k)
	{
		digit[++pos]=k%10;
		k/=10;
	}
	return dfs(pos,false,true);
}


void solve()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(m==0 && n==0) break;
		int ans=fun(m)-fun(n-1);
		printf("%d\n",ans);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

