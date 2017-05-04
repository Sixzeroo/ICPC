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

using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

void solve()
{
	string s;
	while(cin>>s)
	{
		int n=s.size(),ans=0;
		bool flag=1;   //改变一个字符的机会
		for(int i=1;i<n;i++)
		{
			if(s[i]=='K')
			{
				if(s[i-1]=='V') ans++,i++;
				else
				{
					if(flag) flag=0,ans++;
				}
			}
			else
				if(flag && ((i<n-1 && s[i+1]!='K') || i==n-1) && s[i-1]=='V') flag=0,ans++;
		}
		cout<<ans<<endl;
	}
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
