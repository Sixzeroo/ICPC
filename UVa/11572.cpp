#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int maxn=1000005;
int a[maxn];

void solve()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int r=0,l=0,ans=0;
		set<int> S;
        while(r<n)
		{
			while(r<n && !S.count(a[r])) S.insert(a[r++]);
			ans=max(ans,r-l);
			S.erase(a[l++]);
		}
		printf("%d\n",ans);
	}
}

int main()

{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
