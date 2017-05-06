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
#include <map>

using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

map<ll,ll> prime_factor(ll t)
{
	map<ll,ll> ret;
	for(int i=2;i*i<=t;i++)
	{
		while(t%i==0) { ++ret[i];t/=i; }
	}
	if(t!=1) ret[t]=1;
	return ret;
}

ll Euler (ll t)
{
	ll ret=t;
	map<ll,ll> fac=prime_factor(t);
	for(map<ll,ll>::iterator i=fac.begin();i!=fac.end();i++)
		ret=ret*(i->first-1)/i->first;
	return ret;
}

void solve()
{
	ll n;
	while(scanf("%lld",&n)!=EOF && n)
		printf("%lld\n",Euler(Euler(n)));
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
