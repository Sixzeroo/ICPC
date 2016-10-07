#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>
#include<functional>

using namespace std;

#define MAXSIZE 10000
#define mm(a,b) memset(a,b,sizeof(a))

vector<int> edge[MAXSIZE+5];
int indgress[MAXSIZE],record[MAXSIZE],used[MAXSIZE];

void solve()
{
    mm(indgress,0);  //不包含所有的顶点
    mm(edge,0);
    mm(used,0);
    int n,m,a,b,i,j,t=0,y;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        edge[i].clear();
    priority_queue<int> p;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        /*if(indgress[a]<0)
            indgress[a]=0;
        if(indgress[b]<0)
            indgress[b]=0;*/
        indgress[b]++;
        edge[a].push_back(b);
    }
    /*for(i=1;i<=n;i++)
        if(indgress[i]>=0)k++;*/
    for(i=1;i<=n;i++)
        if(!indgress[i])
        {
            p.push(i);
            indgress[i]=-1;
        }
    while(!p.empty())
    {
        j=p.top();
        //used[j]=1;
        record[t++]=j;
        p.pop();//出队列位置放在新元素进来之前
        for(i=0;i<edge[j].size();i++)
        {
            y=edge[j][i];
            indgress[y]--;
            if(!indgress[y])
            {
                p.push(y);
                indgress[y]=-1;
            }
        }
    }
    if(t<n)
    {
        cout<<"-1"<<endl;
        return;
    }
    cout<<record[0];
    for(i=1;i<n;i++)
        cout<<" "<<record[i];
    cout<<endl;
    return;
}

int main()
{
    //freopen("input.txt","r",stdin);
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
