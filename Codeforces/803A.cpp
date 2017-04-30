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
const int maxn=105;
bool a[maxn][maxn];

void out(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}             

void solve()
{
	int n,k;
	while(cin>>n>>k)
	{
		memset(a,0,sizeof(a));
		if(k>n*n)
		{
			printf("-1\n"); 
			continue;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j && k>0)
				{
					a[i][i]=1;
					k--;
				}
				if(i!=j && !a[i][j] && k>1)
				{
					a[i][j]=a[j][i]=1;
					k-=2;
				}
			}
		}
		out(n);
	}
}


int main()
{
    //freopen("input.txt","r",stdin);

	//test();
    solve();
    return 0;
}
