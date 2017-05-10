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
const int maxn=100010;
int n,k;
ll d[maxn];

bool judge(ll s)
{
	ll tmp=0;      //一定要设置成long long
	for(int i=0;i<n;i++)
	{
		if(d[i]>s)   //需要对k进行特判
		{
            tmp+=ceil((d[i]-s)*1.0/(k-1));
		}
	}
	//cout<<"s"<<s<<"tmp:"<<tmp<<endl;
	return tmp<=s;
}

ll fun(ll minv,ll maxv)
{       
	ll l=minv,r=maxv,mid;
	while(l<r)
	{
		//mid=l+((r-l)>>1);  
		mid=(l+r)/2; 
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(judge(mid)) r=mid;
		else l=mid+1;
	}
	return l;
}

void solve()
{
	while(scanf("%d",&n)!=EOF)
	{
		ll minv=INF,maxv=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&d[i]);
			minv=min(minv,d[i]);
			maxv=max(maxv,d[i]);
		}
		scanf("%d",&k);
		if(k==1) 
		{
			printf("%lld\n",maxv);
			continue;
		}
		printf("%lld\n",fun(1,maxv));
	}
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
