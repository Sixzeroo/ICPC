#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn=1000;
const int maxm=100005; 
  
/* ************************************************************************** 
//二分图匹配（匈牙利算法的DFS实现） 
//初始化：g[][]两边顶点的划分情况 
//建立g[i][j]表示i->j的有向边就可以了，是左边向右边的匹配 
//g没有边相连则初始化为0 
//L是匹配左边的顶点数，R是匹配右边的顶点数 
//调用：res=hungary();输出最大匹配数 
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解 
//时间复杂度:O(VE) 
// ***************************************************************************/  
//顶点编号从1开始的  
int LN,RN;//L,R数目  
int g[maxn][maxn], linker[maxn];    //所连得边直接从做到右
bool used[maxn];  
int dfs(int L)//从左边开始找增广路径  
{  
    int R;  
    for(R = 1; R <= RN; R++)  
    {  
        if(g[L][R]!=0 && !used[R])  
        {  
            //找增广路，反向  
            used[R]=true;  
            if(linker[R] == -1 || dfs(linker[R]))  
            {  
                linker[R]=L;  
                return 1;  
            }  
        }  
    }  
    return 0;//这个不要忘了，经常忘记这句  
}  
int hungary()  
{  
    int res = 0 ;  
    int L;  
    memset(linker,-1,sizeof(linker));  
    for( L = 1; L <= LN; L++)  
    {  
        memset(used,0,sizeof(used));  
        if(dfs(L) != 0)  
            res++;  
    }  
    return res;  
}  


void solve()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&LN,&RN);
		int num,tmp;
		memset(g,0,sizeof(g));
		for(int i=1;i<=LN;i++)
		{
			scanf("%d",&num);
			for(int j=0;j<num;j++)
			{
				scanf("%d",&tmp);
                g[i][tmp]=1;
			}
		}
		int ans=hungary();
		if(ans==LN) printf("YES\n");
		else printf("NO\n");
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
