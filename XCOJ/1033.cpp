#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int MOD=1e9;
const int maxn=(1<<20)+10;
const int maxm=10005; 

void solve()
{
	int a,b,num=0;
	char o,s[20];
	while(scanf("%d%c%d=%s",&a,&o,&b,s)!=EOF)
	{
		if(s[0]=='?') continue;
		else if(o=='+' && a+b==atof(s))num++;
		else if(o=='-' && a-b==atof(s))num++;
	}
	printf("%d\n",num);
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
