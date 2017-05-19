#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int MOD=1e9;
const int maxn=10005;
const int maxm=10005; 

int a[maxn],c[maxn];
bool cmp(int x,int y)
{
	return a[x]>a[y];    //从大到小排序
}

void solve()
{
	int k;
	while(cin>>k)
	{
		for(int i=1;i<=3*k;i++)
		{
			cin>>a[i];
			c[i]=i;
		}
		sort(c+1,c+3*k+1,cmp);
		while(1)
		{
			int cnt1=0,cnt2=0;
			for(int i=1;i<=k;i++)
				cnt1+=a[c[i]];
			for(int i=k+1;i<=2*k;i++)
				cnt2+=a[c[i]];
			if(cnt1>k*500 && cnt2>k*500)
			{
				for(int i=1;i<=3*k;i++)
					cout<<c[i]<<endl;
				break;
			}
			int x=rand()%k+1,y=rand()%k+k+1;
			swap(c[x],c[y]);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
