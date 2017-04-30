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
const ll maxn=1000000003;
const ll maxp=1000000003;

bool is_prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return x!=1;
}


ll fast(ll p, ll a)
{
    ll r = p, t = 1, mod = p;
    while(r > 0)
    {
        if(r&1) t = ((t%mod)*(a%mod))%mod;
        a = ((a%mod)*(a%mod))%mod;
        r >>= 1;
    }
    return t%mod;
}

void solve()
{
	ll a,p;
	while(cin>>p>>a &&(p||a))
	{
        if(is_prime(p))
            printf("no\n");
		else if(fast(p,a)==a)
			printf("yes\n");
		else
			printf("no\n");

	}
}


int main()
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
