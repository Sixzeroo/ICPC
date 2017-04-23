#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
#define INF 0x3f3f3f3f
const int maxn=1005;
const int maxp=100005;
bool is_prime[maxp];
int prime[maxp],num;
int n,m,d;
bool visit[maxn];
int ans[maxn];

void init()
{
	num=0;
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<maxp;i++)
	{
		if(is_prime[i]) prime[num++]=i;
		for(int j=0;j<num && i*prime[j]<maxp;j++)
		{
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}

bool judge(int pos,int nu)  //判断pos位置放置num值是否可行
{
	if(pos==0)
		return true;
	int l=pos-d+1;
    if(l<0)
        l=0;
	int sum=nu;
	for(int i=pos-1;i>=l;i--)
	{
		sum+=ans[i];
		if(is_prime[sum])
			return false;
	}
	return true;
}

bool dfs(int u)
{
	if(u==m-n+1)
		return true;
	for(int i=n;i<=m;i++)  //枚举每个可以插入的数
	{
		if(!visit[i] && judge(u,i))
		{
			ans[u]=i;    //记录下来为考虑后面的数做准备
			visit[i]=true;
			if(dfs(u+1))
				return true;
			visit[i]=false; // 回溯
		}
	}
	return false;
}

void solve()
{
	init();
	while(scanf("%d %d %d",&n,&m,&d)!=EOF)
	{
		if(n==0&&m==0&&d==0)
			break;
		memset(visit,false,sizeof(visit));
		memset(ans,0,sizeof(ans));
		if(dfs(0))
		{
			for(int i=0;i<m-n+1;i++)
			{
				printf("%d",ans[i]);
				if(i!=m-n)
					printf(",");
			}
			printf("\n");
		}
		else
			printf("No anti-prime sequence exists.\n");
	}
}


int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
