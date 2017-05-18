#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=200010;
const int maxm=100005; 
int a[maxn];

void solve()
{
	int n,k,r;
	double ans;
	while(cin>>n>>k)
	{
		double tmp=0;
		ans=0;
		int weeks=n-k+1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<k;i++)
			tmp+=a[i];
		for(int i=k-1;i<n;i++)
		{
			ans+=tmp/weeks;
			tmp+=a[i+1];
			tmp-=a[i-k+1];
		}
		printf("%.12lf\n",ans);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}
