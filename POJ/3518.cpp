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
const int maxp=1299710;
bool is_prime[maxp];
int prime[maxp],num;

void init()    //欧拉筛选素数打表
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

void solve()
{
	int a;
	init();
	while(scanf("%d",&a)!=EOF && a)
	{
		int ans=0,t=a;
		while(!is_prime[t--])
			ans++;
		t=a;
		while(!is_prime[t++])
			ans++;
		printf("%d\n",ans);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
