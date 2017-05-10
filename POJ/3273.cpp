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
const int maxn=100010;
int n,m;
int d[maxn];

bool judge(int s)
{
	int num=0,tmp=0;
	for(int i=0;i<n;i++)
	{
		if(tmp+d[i]<=s) tmp+=d[i];
		else
		{
			//cout<<tmp<<" ";
			tmp=d[i];
			num++;
		}
	}
	if(tmp) num++;
	//cout<<num<<endl;
	return num<=m;
}

int fun(int maxv,int sum)
{       
	int l=maxv,r=sum,mid;
	while(l<r)
	{
		//mid=l+((r-l)>>1);  
		mid=(l+r)/2; 
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(judge(mid)) r=mid;
		else l=mid+1;
	}
	return l;
}

void solve()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int sum=0,maxv=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&d[i]);
			sum+=d[i];
			maxv=max(maxv,d[i]);
		}
		printf("%d\n",fun(maxv,sum));
	}
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
