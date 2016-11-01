#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<sstream>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<algorithm>
#include<set>
#include<functional>
#include<stack>
#include<iterator>
using namespace std;


typedef struct statu
{
    double g[5][5];
}sta;

sta mul(sta a,sta b)
{
    sta c;
    int i,j,k;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            c.g[i][j]=0;
            for(k=0;k<5;k++)
                c.g[i][j]+=a.g[i][k]*b.g[k][j];    //i��j�ж�����·
        }
    }
    return c;
}

sta pow(sta a,int d)   //���ö����������ص�
{
    sta b,c;
    b=a;
    memset(c.g,0,sizeof(c.g));
    for(int i=0;i<5;i++)
        c.g[i][i]=1;     //�ۼ�λ��ʼ��
    while(d)
    {
        if(d&1)c=mul(c,b);   //�ۼ�λ
        b=mul(b,b);    //����������λ
        d/=2;
    }
    return c;
}

void solve()
{
    int n,s,maxj;
    double maxi=0;
    cin>>n;
    int i,j;
    sta a,ans;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>a.g[j][i];     //j��ǰʹ����ǰ��������Ӧ
    cin>>s;
    if(n==1)
    {
        cout<<s<<endl;
        return;
    }
    ans=pow(a,n-1);
    //for(i=0;i<5;i++)    //�Ѿ�ȷ�����
        for(j=4;j>=0;j--)    //����ʹ��for(j=0;j<5;j++),ԭ�򣺸�����ͬҪѡ��С�ģ���γ˷�����ʱ����ȷ�ģ�ͨ��1e-6����ý��ƾ�ȷ�Ľ�
            if(ans.g[s-1][j]>maxi||abs(ans.g[s-1][j]-maxi)<1e-6)
            {
                maxi=ans.g[s-1][j];
                maxj=j;
            }
    cout<<maxj+1<<endl;
    return;
}



int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
