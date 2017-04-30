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
const int maxn=300004;
int a[maxn],b[maxn],n;

void solve()
{
	while(cin>>n)
	{
        fill(b,b+n,n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		int lst=-n;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
				lst=i;
			b[i]=min(b[i],i-lst);
		}
		lst=2*n;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]==0)
				lst=i;
			b[i]=min(b[i],lst-i);
		}
		for(int i=0;i<n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
}

int main()
{
    //freopen("input.txt","r",stdin);

	//test();
    solve();
    return 0;
}
