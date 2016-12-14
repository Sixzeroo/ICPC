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

#define SIZE_V 300
#define SIZE_E 100000
#define INF 0x3f3f3f3f
typedef long long ll;

int G[SIZE_V][SIZE_V];
int prev[SIZE_V];   //ÿ������Ӧ��ǰ�����
bool visited[SIZE_V];
int V,E;

int Augment()  //ʹ��bfsһ���ҳ�һ������·
{
    int v,i;
    queue<int> q;
    memset(prev,0,sizeof(prev));
    memset(visited,0,sizeof(visited));
    prev[1]=0;
    visited[1]=1;
    q.push(1);
    bool bfindpath=0; //��ʶ�Ƿ��ҵ�����·
    while(!q.empty())
    {
        v=q.front();
        q.pop();
        for(i=1;i<=V;i++)
        {
            if(G[v][i]>0&&!visited[i]) //������Ȼ������������
            {
                prev[i]=v;
                visited[i]=1;
                if(i==V)  //�ҵ�һ������·
                {
                    bfindpath=true;
                    q=queue<int> ();   //��ն���
                    break;
                }
                else
                    q.push(i);
            }
        }
    }
    if(!bfindpath)  //û���ҵ�����·
        return 0;
    //�ҳ���������������������·�ϵ���С��
    int minflow=INF;
    v=V;
    while(prev[v])
    {
        minflow=min(minflow,G[prev[v]][v]);    //ע������������
        v=prev[v];
    }
    //�ı���������ӷ����
    v=V;
    while(prev[v])
    {
        G[prev[v]][v]-=minflow;
        G[v][prev[v]]+=minflow;
        v=prev[v];
    }
    return minflow;
}

void solve()
{
    while(cin>>E>>V)
    {
        int i,j,k;
        int s,e,c;
        memset(G,0,sizeof(G));
        for(i=0;i<E;i++)
        {
            cin>>s>>e>>c;
            G[s][e]+=c;    //�ۼӷ�ʽ�����ر�
        }
        int maxflow=0;
        int aug;
        while(aug=Augment())
            maxflow+=aug;  //ͨ��Ѱ������·�����������µ���������
        cout<<maxflow<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
