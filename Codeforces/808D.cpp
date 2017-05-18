#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
#define MAXX 2000000000
const int maxn=100005;
const int maxm=100005; 
int a[maxn],n;
ll s[maxn],tot;

void solve()
{
	while(scanf("%d",&n)!=EOF)
	{
		tot=0;
		s[0]=0;
		multiset<int> s1,s2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s2.insert(a[i]);
			tot+=a[i];
			s[i]=s[i-1]+a[i];
		}
		if(tot&1) 
		{
			printf("NO\n");
			continue;
		}
		ll A,B,tmp;
		bool endflag=1;
		for(int i=1;i<=n;i++)
		{
			A=s[i],B=s[n]-s[i];
			if(A==B)
			{
				printf("YES\n");
				endflag=0;
				break;
			}
			tmp=A-B;
			s2.erase(s2.find(a[i]));
			s1.insert(a[i]);
			if(tmp>0 && tmp%2==0 && tmp<=MAXX)  //差值为偶数
			{
				if(s1.find(tmp/2)!=s1.end())
				{
					printf("YES\n");
					endflag=0;
					break;
				}
			}
			if(tmp<0 && tmp%2==0 && tmp>=-MAXX)
			{
				if(s2.find(-tmp/2)!=s2.end())
				{
					printf("YES\n");
					endflag=0;
					break;
				}
			}
		}
		if(endflag) printf("NO\n");
	}
}


int main()
{
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}
