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
typedef long long ll;
const int maxn=1000003;
const int maxp=50050;
bool is_prime[maxp];
int prime[maxp],num;
bool is_prime2[maxn];
ll prime2[maxn],num2;

void prime_init()
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

void bigger_prime(ll L,ll R)
{
	memset(is_prime2,1,sizeof(is_prime2));
    ll mul;
	for(int i=0;i<num && prime[i]<=R;i++)
	{
		if(prime[i]<=L)
            mul=(L-prime[i])/prime[i];           //获得相差的倍数
        else
            mul=2;
		while(mul*prime[i]<L || mul<=1) mul++;     //修正倍数值,不能够等于一
		for(ll j=mul*prime[i];j<=R;j+=prime[i])
			if(j>=L)
                is_prime2[j-L]=0;
	}
    num2=0;
	for(int i=0;i<=R-L;i++)
	{
		if(is_prime2[i])
        {
            if(i+L==1) continue;   //注意要排除1这个不是素数的数
            prime2[num2++]=i+L;
        }

	}
}

void solve()
{
	ll L,R;
	prime_init();
	while(scanf("%lld %lld",&L,&R)!=EOF)
	{
		bigger_prime(L,R);
		ll maxv=0,minv=INF,maxid,minid;
        for(int i=0;i<num2-1;i++)
        {
            if(maxv<prime2[i+1]-prime2[i])
                maxv=prime2[i+1]-prime2[i],maxid=i;
            if(minv>prime2[i+1]-prime2[i])
                minv=prime2[i+1]-prime2[i],minid=i;
        }
        if(num2<2)
            printf("There are no adjacent primes.\n");
		else
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",prime2[minid],prime2[minid+1],prime2[maxid],prime2[maxid+1]);

	}
}

int main()
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
