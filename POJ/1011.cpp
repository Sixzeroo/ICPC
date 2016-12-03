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

using namespace std;

int a[65],side,n,vn;
bool used[65];

bool dfs(int num,int cur,int s)//cur������� s�ܺ� num�Ѿ���ɵı���
{
    if(num==vn)
        return true;
    int same=-1;   //��¼������ǵ���ͬ��ֵ
    for(int i=cur;i>=0;i--)
    {
        if(used[i]||same==a[i])  //�����Ѿ����ǹ��ĺ��ظ����ǵ�
            continue;
        used[i]=true;
        if(s+a[i]==side)
        {
            if(dfs(num+1,n-1,0))  //�ҵ���ʱ������
                return true;
            else
                same=a[i];    //��¼���ɹ���ֵ
        }
        else if(s+a[i]<side)
        {
            if(dfs(num,i,s+a[i]))    //��С��������
                return true;
            else
                same=a[i];
        }
        used[i]=false;
        if(s==0)  //��Ϊ�Ѿ��ź������û����ԣ�����Ͳ�������Ժ�
            break;
    }
    return false;
}


void solve()
{
    int m,i;
    while(cin>>n)
    {
        if(n==0)
            break;
        memset(used,0,sizeof(used));

        int sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }

        sort(a,a+n);

        m=a[n-1];
        for(i=m;i<=sum;i++)
        {
            if(sum%i!=0)
                continue;
            side=i;
            vn=sum/i;  //���ӵĳ�ʼ��Ŀ
            if(dfs(1,n-1,0))
            {
                cout<<i<<endl;
                i=sum+1;
            }
        }
        if(i==m)
            cout<<"Not found"<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}

