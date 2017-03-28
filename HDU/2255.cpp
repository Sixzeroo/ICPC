#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define in(a) scanf("%d",&a)

using namespace std;
#define INF 0x3f3f3f3f

const int maxn=317;

int nx,ny;  //两边的点数
int g[maxn][maxn];   //建图
int linker[maxn],lx[maxn],ly[maxn];     //y中欧各个点的匹配状态,x y 中各个点的标号
int slack[maxn];        //松弛量数组
bool visx[maxn],visy[maxn];

bool dfs(int x)
{
	visx[x]=true;
	for(int y=0;y<ny;y++)
	{
		if(visy[y]) continue;
		int tmp=lx[x]+ly[y]-g[x][y];
		if(tmp==0)    //顶标符合要求
		{
			visy[y]=true;
			if(linker[y]==-1 || dfs(linker[y]))
			{
				linker[y]=x;
				return true;
			}
			
		}
		else if(slack[y]>tmp)
			slack[y] =tmp;        //更新松弛量
	}
    return false;
}

int KM()
{
	memset(linker,-1,sizeof(linker));     //初始化一开始匹配的点
	memset(ly,0,sizeof(ly));      //y的顶标先全部变成0
	//初始化顶标
	for(int i=0;i<nx;i++)
	{
		lx[i]= -INF;            //求最大值，首先初始化为最小值
        for(int j=0;j<ny;j++)
			if(g[i][j]>lx[i]) lx[i]=g[i][j];
	}
    for(int x=0;x<nx;x++)
	{
		for(int i=0;i<ny;i++)
			slack[i]=INF;
		//算法核心部分
		while(true)
		{
			memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
			if(dfs(x)) break;
			int d= INF;
			//优化顶标
			for(int i=0;i<ny;i++)
				if(!visy[i] && d>slack[i])
					d=slack[i];          //求出最小一个slack值
			for(int i=0;i<nx;i++)
				if(visx[i])
					lx[i]-=d;
			for(int i=0;i<ny;i++)
			{
				if(visy[i]) ly[i]+=d;
				else
					slack[i] -=d;
			}
		}
	}
	int res=0;
	for(int i=0;i<ny;i++)
		if(linker[i]!=-1)
			res+=g[linker[i]][i];
	return res;
}

void solve()
{
	int n;
	while(in(n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				in(g[i][j]);       //建图
		}
		nx=ny=n;
		int ans=KM();
		printf("%d\n",ans);
	}
}

int main()                         
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
