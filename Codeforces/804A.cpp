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

void solve()
{
	int n;
	while(cin>>n)
	{
		if(n%2)
			cout<<n/2<<endl;
		else
			cout<<n/2-1<<endl;
	}
}

int main() 
{
    //freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
