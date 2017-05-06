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
#include <map>

using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
const int maxn=105;

void solve()
{
	int a[maxn];
	int n,m,k;
	while(cin>>n>>m>>k)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		m--;
		int pos=0;
		while(m-pos>=0 || m+pos<n)
		{
			if(m-pos>=0 && a[m-pos]<=k && a[m-pos]!=0)
			{
				cout<<pos*10<<endl;
				break;
			}
			if(m+pos<n && a[m+pos]<=k && a[m+pos]!=0)
			{
				cout<<pos*10<<endl;
				break;
			}
			pos++;
		}
	}
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
