#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int maxn=5006;

int dir[maxn],f[maxn];    //存放初始状态和反转情况
int N;

int calc(int k)
{
	memset(f,0,sizeof(f));
	int res=0;        //最后反转的次数
	int sum=0;        //之前区间的反转对当前节点的影响数
	for(int i=0;i+k<=N;i++)
	{
		if((dir[i]+sum)%2)    //需要进行反转
		{
			res++;
			f[i]=1;         //会对后面的产生影响
		}
		sum+=f[i];
		if(i-k+1>=0)
			sum-=f[i-k+1];
	}
	for(int i=N-k+1;i<N;i++)  //无法进行反转的阶段
	{
		if((dir[i]+sum)%2)
			return -1;    //无解
		if(i-k+1>=0)
			sum-=f[i-k+1];
	}
	return res;	
}

void solve()
{
	char ch[2];
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%s",&ch);
			if(ch[0]=='F')
				dir[i]=0;
			else
				dir[i]=1;
		}
		int minid=1,minva=N;
		for(int k=1;k<=N;k++)
		{
			int tmp=calc(k);
			if(tmp>=0 && tmp<minva)
			{
				minva=tmp;
				minid=k;
			}
		}
		printf("%d %d\n",minid,minva);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
