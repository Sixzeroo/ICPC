#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1001][1001];
string b;

//自底向上使用动态规划算法
void fun()
{
    int i,j,n;
    n=b.length();
    for(i=0;i<n;i++)   //对只有一个字符的串进行处理
        a[i][i]=0;
    for(i=0;i<n-1;i++)   //对只有两个字符的串处理
        a[i][i+1]=(b[i]==b[i+1])?0:1;
    for(j=2;j<n;j++)    //利用状态转移方程实现动态规划算法
        for(i=0;i+j<n;i++)
            if(b[i]==b[i+j])a[i][i+j]=a[i+1][i+j-1];
            else a[i][i+j]=min(a[i+1][i+j],a[i][i+j-1])+1;
    cout<<a[0][n-1]<<endl;
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);  //重定向直接在文件中读入数据
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>b;
        fun();
    }
    return 0;
}
