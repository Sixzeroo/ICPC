#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;
#define MAXSIZE 100005
#define in(a) scanf("%d",&a)

typedef pair<int,int> pa;

int n,l,p;
pa a[MAXSIZE];


void solve()
{
    int i,m,t,ans,tem,d;   //���л�ʣ������m
    t=ans=0;
    for(i=0;i<n;i++)
    {
        in(a[i].first);
        in(a[i].second);
    }
    in(l);
    in(p);
    for(i=0;i<n;i++)
        a[i].first=l-a[i].first;
    sort(a,a+n);     //���������ݲ�һ���ǰ���˳������ģ�Ҫ��������
    priority_queue<int> q;
    n++;
    m=p;
    a[i].first=l;
    a[i].second=0;
    for(i=0;i<n;i++)
    {
        d=a[i].first-t;
        while(m<d)   //���ܼ��ʹ�����ֹһ��
        {
            if(q.empty())
            {
                printf("-1\n");
                return ;
            }
            m+=q.top();
            q.pop();
            ans++;
        }
        t=a[i].first;
        m-=d;
        q.push(a[i].second);   //λ��Ӧ�÷������
    }
    printf("%d\n",ans);
    return;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(in(n)!=EOF)
    {
        solve();
    }
    return 0;
}
