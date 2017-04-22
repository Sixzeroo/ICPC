#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void solve()
{
	string s;
	while(cin>>s)
	{
		int n=s.size();
		int u=0;
		if(n==1)
		{
			printf("YES\n");
			return ;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]!=s[n-1-i])
				u++;
		}
		if(u==2)
			printf("YES\n");
		else if(u==0 && n%2==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
