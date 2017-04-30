nclude <iostream>
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
const int maxn=300004;
#define ll long long

void solve()
{
	ll n,k;
	while(cin>>n>>k)
	{
		if(k>(ll)1e8)     //分割的段数过大不存在解
		{
			printf("-1\n");	
			continue;
		}
		ll b=n/(k*(k+1)/2);
		if(b==0)
		{
			printf("-1\n");
			continue;
		}
		ll r=1;       //最大公因数
		for(ll x=1;x*x<=n;x++)
		{
			if(n%x!=0) continue;
			if(x<=b && x>r) r=x;
			if(n/x<=b && n/x>r) r=n/x;
		}
		for(ll i=1;i<k;i++)
            cout<<i*r<<" ";
		ll tmp=n-(k*(k-1)/2)*r;
		cout<<tmp<<endl;
	}
}

int main()
{
    //freopen("input.txt","r",stdin);

	//test();
    solve();
    return 0;
}
