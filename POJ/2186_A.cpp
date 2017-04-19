#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int maxn=10005;
const int maxm=50005;

int v;
vector<int> g[maxn];
vector<int> rg[maxn];
vector<int> vs;
bool used[maxm];
int n,m;
int cmp[maxm];

void addedge(int u,int v)
{
	g[u].push_back(v);
	rg[v].push_back(u);
}

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<g[v].size();i++)
	{
		if(!used[g[v][i]])
			dfs(g[v][i]);
	}
	vs.push_back(v);     //后序遍历将点添加到一个序列当中去
}

void rdfs(int v,int k)
{
	used[v]=true;
	cmp[v]=k;       //为强连通分量重的每一个点添加标号
	for(int i=0;i<rg[v].size();i++)
	{
		if(!used[rg[v][i]])
			rdfs(rg[v][i],k);
	}
}

int scc()
{
	//后序遍历排序标号
	memset(used,false,sizeof(used));
	vs.clear();
	for(int i=0;i<v;i++)
	{
		if(!used[i])
			dfs(i);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)     //反向进行dfs
		if(!used[vs[i]])
			rdfs(vs[i],k++);
	return k;   //最后的强连通分量的个数
}

void solve()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		v=n;
		int a,b;
		for(int i=0;i<m;i++)
        {
            scanf("%d %d", &a, &b);
            addedge(a - 1, b - 1);    //包含了0
        }

        int nn=scc();
        int u=0,num=0;
        for(int i=0;i<v;i++)
        {
            if(cmp[i]==nn-1)
            {
                u=i;
                num++;
            }
        }
        memset(used,false,sizeof(used));
        rdfs(u,0);
        for(int i=0;i<v;i++)
        {
            if(!used[i])
            {
                num=0;
                break;
            }
        }
        printf("%d\n",num);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
