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
const int maxn=50005;
int l,n,m;
int d[maxn];

bool judge(int s)
{
	int j=0,num=0;
	for(int i=1;i<n;i++)
	{
		if(d[i]-d[j]<s) num++;
		else j=i;
	}
	//cout<<"s:"<<s<<"num:"<<num<<"m:"<<m<<endl;
	return num<=m;
}

int fun()
{
	int ll=0,rr=l+1;
	int mid;
	while(ll+1<rr)
	{
		mid=(ll+rr)>>1;
		//cout<<ll<<" "<<rr<<" "<<mid<<endl;
		if(judge(mid))
			ll=mid;
		else
			rr=mid;
	}
	return ll;
}

void solve()
{
	while(scanf("%d %d %d",&l,&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]);
        d[0]=0;
		d[n+1]=l;
		n+=2;
		sort(d,d+n);
		int ans=fun();
		printf("%d\n",ans);
	}
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
