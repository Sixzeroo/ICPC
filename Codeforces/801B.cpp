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
	string a,b;
	while(cin>>a>>b)
	{
		bool flag=1;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>b[i]) a[i]=b[i];
			else if(a[i]<b[i]) 
			{
				cout<<"-1"<<endl;
				flag=0;
				break;
			}
		}
		if(flag)
			cout<<a<<endl;
	}
}

int main() 
{
    //freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
