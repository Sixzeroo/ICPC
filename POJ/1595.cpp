#include <iostream>
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
const int maxn=100003;
const int maxp=100003;
bool is_prime[maxp];
int prime[maxp],num;

void prime_init()
{
	num=0;
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=0;
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
	int n,c;
	prime_init();
	while(cin>>n>>c)
	{
		int id=0;
		for(int i=0;i<num;i++)
		{
			if(prime[i]<=n)
				id=i+1;
			else
                break;
		}
        if(c>=id)
        {
            printf("%d %d:",n,c);
            printf(" 1");
            for(int i=0;i<id;i++)
                printf(" %d",prime[i]);
            printf("\n\n");
            continue;
        }
		if(id%2)
		{
			id/=2;
			printf("%d %d:",n,c);
			for(int i=id-c;i<id+c;i++)
				printf(" %d",prime[i]);
			printf("\n\n");
		}
		else
		{
			id/=2;
			printf("%d %d:",n,c);
			for(int i=id-c;i<id+c-1;i++)
				printf(" %d",prime[i]);
			printf("\n\n");
		}
	}
}


int main()
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
