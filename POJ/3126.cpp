#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f
const int maxn=10005;
const int maxp=10005;
bool is_prime[maxp];
int prime[maxp],num;
int visit[maxn];
struct poin
{
	string num;
	int step;
	poin(string num,int step):num(num),step(step) {}
};

void init()    //欧拉筛选素数打表
{
	num=0;
    memset(is_prime,true,sizeof(is_prime));
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<maxp;i++)
	{
		if(is_prime[i]) prime[num++]=i;
		for(int j=0;j<num && i*prime[j]<maxp;j++)
		{
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}

void solve()
{
	int t;
	cin>>t;
	string a,b;
	while(t--)
	{
		cin>>a>>b;
		int ans=-1;
		init();
		memset(visit,0,sizeof(visit));
		queue<poin> que;
		que.push(poin(a,0));
		while(!que.empty())
		{
			poin p=que.front();
			que.pop();
			if(p.num==b)
			{
				ans=p.step;
				break;
			}
			for(int i=3;i>=0;i--)
			{
				int be= (i==0)?1:0;
				string c=p.num;
				for(int j=be;j<10;j++)
				{
					c[i]=j+'0';
					int next=atoi(c.c_str());
					if(!visit[next] && is_prime[next] &&c!=p.num)  //防止出不来了
					{
						//cout<<c<<endl;
						visit[next]=1;
						que.push(poin(c,p.step+1));
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
