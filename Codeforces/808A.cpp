#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=105;
const int maxm=100005; 

void solve()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;n/(i*10);i*=10);
	printf("%d",n/i*i+i-n);
}

int main()
{
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}
