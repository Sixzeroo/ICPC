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

struct node
{
    int x,y;
    int step; //记录从起点到这一个点的步数
};

int go_x[8]={2,1,-1,-2,-2,-1,1,2},go_y[8]={1,2,2,1,-1,-2,-2,-1};

int visited[SIZE][SIZE];
int n;

node start,finish;

int seaching()
{
    start.step=0;
    queue<node> que;
    que.push(start);
    memset(visited,0,sizeof(visited));
    visited[start.x][start.y]=1;

    while(!que.empty())
    {
        node v=que.front();
        que.pop();

        for(int i=0;i<8;i++)
        {
            node ne;
            ne.x=v.x+go_x[i];
            ne.y=v.y+go_y[i];
            ne.step=v.step+1;

            if(ne.x<0||ne.y<0||ne.x>=n||ne.y>=n)
                continue;
            if(visited[ne.x][ne.y])
                continue;
            visited[ne.x][ne.y]=1;

            if(ne.x==finish.x&&ne.y==finish.y)
                return ne.step;
            que.push(ne);
        }
    }
    return 0;
}

void solve()
{
    int t;
    in(t);
    while(t--)
    {
        in(n);
        in(start.x);
        in(start.y);
        in(finish.x);
        in(finish.y);
        int res=seaching();
        printf("%ld\n",res);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
