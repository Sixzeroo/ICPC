#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <utility>

using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
const int maxn=10000;
bool is_prime[maxn];
int prime[maxn];
int num;

void init_prime()
{
	num=0;
	memset(is_prime,1,sizeof(is_prime));
	is_prime[1]=is_prime[0]=false;
	for(int i=2;i<maxn;i++ )
	{
		if(is_prime[i]) prime[num++]=i;
		for(int j=0;j<num && i*prime[j]<maxn;j++)
		{
			is_prime[i*prime[j]]=false;
			if(i%prime[j]) break;
		}
	}
}

void solve()
{
	int a,b;
	init_prime();
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		int tmp=0,ans[10000];
		if(b==1) 
		{
			cout<<a<<endl;
			continue;
		}
		while(a!=1)
		{
			for(int i=0;i<num;i++)
			{
				while(a%prime[i]==0) 
				{
					if(tmp==b-1)
					{
						ans[tmp++]=a;
						break;
					}
					ans[tmp++]=prime[i];
					a/=prime[i];
				}
				if(tmp==b) break;
			}
			if(tmp==b)break;
		}
        if(tmp<b) cout<<"-1";
	    else
	    	for(int i=0;i<tmp;i++)
					cout<<ans[i]<<" ";
		cout<<endl;
	}
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
