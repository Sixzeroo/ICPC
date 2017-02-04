#include <iostream>
#include <cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;
#define SIZE 30005
#define INF 0x3f3f3f3f

int fa[SIZE],son[SIZE],rm[SIZE];  //并查集，根结点下子结点的数目



void init()
{
    for(int i=1;i<SIZE;i++)
    {
        fa[i]=i;
        son[i]=1;
        rm[i]=0;   //初始情况下每个结点下面的结点数目为0
    }
}

int Find(int x)
{
    if(fa[x]==x)
        return fa[x];
    int t=fa[x];
    fa[x]=Find(fa[x]);     //压缩路径
    rm[x]+=rm[t];       //压住的结点数相加
    return fa[x];
}

void Union(int x,int y)  //x放在y上
{
    int fx=Find(x);
    int fy=Find(y);

    if(fx!=fy)
    {
        fa[fx]=fy;
        rm[fx]=son[fy];    //加上的结点压住的结点数目刚好是y结点的子结点数目
        son[fy]+=son[fx];   //更新子结点的数目
    }
}

void solve()
{
    int p;
    init();
    scanf("%d",&p);
    char ch;
    int x,y,c;
    for(int i=0;i<p;i++)
    {
        cin>>ch;
        if(ch=='M')
        {
            scanf("%d%d",&x,&y);
            Union(y,x);
        }
        else
        {
            scanf("%d",&c);
            printf("%d\n", son[Find(c)]-rm[c]-1);
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
