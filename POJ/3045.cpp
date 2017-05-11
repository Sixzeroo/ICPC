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
ll sum[maxn];

struct node
{
	ll a,b,c; //node(int aa,int bb,int cc):a(aa),b(bb),c(cc);{};
}s[maxn];

bool Cmpare(const node & nodea,const node &nodeb)
{
	return nodea.c<nodeb.c;
}

void test(int n)
{
	for(int i=0;i<n;i++)
		cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<endl;
}

void solve()
{
	ll n;
	while(scanf("%lld",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lld %lld",&s[i].a,&s[i].b);
			s[i].c=s[i].a+s[i].b;
		}
		sort(s,s+n,Cmpare);
		//test(n);
		sum[0]=s[0].a;
		ll maxn=sum[0]-s[0].c;   //一定要包含第一种情况
		for(int i=1;i<n;i++)
		{
			sum[i]=sum[i-1]+s[i].a;
			maxn=max(sum[i]-s[i].c,maxn);
		}
		printf("%lld\n",maxn);
	}
}

int main() 
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
