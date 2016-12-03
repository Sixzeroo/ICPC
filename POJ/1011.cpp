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

bool dfs(int num,int cur,int s)//cur搜索起点 s总和 num已经完成的边数
{
    if(num==vn)
        return true;
    int same=-1;   //记录排序后考虑的相同的值
    for(int i=cur;i>=0;i--)
    {
        if(used[i]||same==a[i])  //跳过已经考虑过的和重复考虑的
            continue;
        used[i]=true;
        if(s+a[i]==side)
        {
            if(dfs(num+1,n-1,0))  //找到的时候才输出
                return true;
            else
                same=a[i];    //记录不成功的值
        }
        else if(s+a[i]<side)
        {
            if(dfs(num,i,s+a[i]))    //往小的数考虑
                return true;
            else
                same=a[i];
        }
        used[i]=false;
        if(s==0)  //因为已经排好序，这次没有配对，后面就不可能配对好
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
            vn=sum/i;  //棒子的初始数目
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

