#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
#define INF 0x3f3f3f3f
const int maxn=100005;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int a[maxn];

void solve()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("YES\n");
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int g=gcd(a[0],a[1]);
		for(int i=2;i<n;i++)
			g=gcd(g,a[i]);
		if(g>1)
			printf("0\n");
		else
		{
			int ans=0;
			for(int i=0;i<n;i++)
			{
				if(!(a[i]&1))   //对奇数进行操作
					continue;
				if(i==n-1)
					ans+=2;
				else
				{
					int tmp=a[i];
					a[i]=a[i]-a[i+1];
					a[i+1]=tmp+a[i+1];
					ans++;
					if(a[i]&1)   //进行两步操作
					{
						tmp=a[i];
						a[i]=a[i]-a[i+1];
						a[i+1]=tmp+a[i+1];
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
