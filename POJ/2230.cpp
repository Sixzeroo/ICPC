#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<utility>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<sstream>

using namespace std;

#define SIZE 305
#define INF 0x3f3f3f3f
#define in(a) scanf("%d",&a)
typedef long long ll;
#define MAX_V 50005
#define MAX_E 10005


vector<int> edge[MAX_V];

void eular(int init)
{
    for(int i=0;i<edge[init].size();i++)
    {
        int tem=edge[init][i];
        if(tem==-1)
            continue;
        edge[init][i]=-1;
        eular(tem);
    }
    printf("%d\n",init);
}

int V,E;

void solve()
{
    in(V);
    in(E);
    for(int i=0;i<E;i++)
    {
        int x,y;
        in(x);
        in(y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    eular(1);
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
