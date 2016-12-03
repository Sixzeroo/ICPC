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

int a[22],side,n;
bool used[22];

bool dfs(int num,int cur,int s)//cur搜索起点 s总和 num已经完成的边数
{
    if(num==4)
        return true;
    int tag=0;   //标记有没有找到值
    bool res=false;
    for(int i=cur;i>=0;i--)
    {
        if(!used[i]&&s+a[i]<=side)  //满足条件递归搜索
        {
            used[i]=true;
            if(s+a[i]==side)
            {
                if(dfs(num+1,n-1,0))  //找到的时候才输出
                    return true;
            }
            else
            {
                if(dfs(num,i,s+a[i]))    //往小的数考虑
                    return true;
            }
            used[i]=false;
        }
    }
    return false;
}


void solve()
{
    int m,i,j;
    cin>>m;
    while(m--)
    {
        memset(used,0,sizeof(used));

        int sum=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%4!=0)   //剪枝1  不可能成为正方形
        {
            cout<<"no"<<endl;
            continue;
        }
        side=sum/4;
        sort(a,a+n);
        if(side<a[n-1])   //剪枝2  最长边比算出来的边长大
        {
            cout<<"no"<<endl;
            continue;
        }
        if(dfs(1,n-1,0))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}

