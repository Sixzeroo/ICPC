nclude <iostream>
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
const int maxn=10000;
const int MOD=1e9+7;

void solve()
{
	string a;
	while(cin>>a)
	{
		ll tmp=0,ans=0,num=0;
		for(int i=a.size()-1;i>=0;i--)
		{
			if(a[i]=='a')
			{
				ans=(ans+tmp)%MOD;
				tmp=(2*tmp)%MOD;
			}
			else
				tmp++;
		}
		cout<<ans<<endl;
	}
}

int main() 
{
    //freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
