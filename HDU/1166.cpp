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
const int maxn=50005;
const int maxm=10005; 

int N,c[maxn];    //树状数组

int lowbit(int i)
{
	return i&(-i);   //得到最高位1以后的剩下的数的二进制数
}

//修改节点操作（添加值）
void add(int i,int value)  //i表示序号
{
	while(i<=N)
	{
		c[i]+=value;
		i+=lowbit(i);
	}
}

//求和操作
int sum(int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=c[i];
		i-=lowbit(i);
	}
	return sum;
}

void solve()
{
	int t;
	scanf("%d",&t);
	for(int id=1;id<=t;id++)
	{
		printf("Case %d:\n",id);
		memset(c,0,sizeof(c));
		scanf("%d",&N);
		int d;
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&d);
			add(i,d);
		}
		string s;
		int x,y;
		while(cin>>s && s!="End")
		{
			scanf("%d %d",&x,&y);
			if(s=="Query") printf("%d\n",sum(y)-sum(x-1));
			else if(s=="Add") add(x,y);
			else if(s=="Sub") add(x,-y);
		}

	}
}



int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
