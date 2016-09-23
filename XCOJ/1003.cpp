#include<iostream>
#include<cstdio>   //使用文件重定向输入
#include<cstring>
#include<algorithm>
using namespace std;
int a[31][31];

//一字蛇形阵
void f1(int n)
{
    int i,j,p=1,q=n*n;
    for(i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(j=0;j<i;j++)
            {
                a[i-j-1][j]=p++;
                a[n-i+j][n-j-1]=q--;
            }
        }
        else
            for(j=0;j<i;j++)
            {
                a[j][i-j-1]=p++;
                a[n-j-1][n-i+j]=q--;
            }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%4.d",a[i][j]);
        cout<<endl;
    }
    return;
}

//回型蛇形阵
void f2(int n)
{
    int a[31][31],i,j,d=n*n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;
    int p=n-1,q=0;
    a[p][q]=d--;
    while(d>0)
    {
        while(!a[p-1][q]&&p>=1&&q>=0)
            a[--p][q]=d--;
        while(!a[p][q+1]&&p>=0&&q<n-1)
            a[p][++q]=d--;
        while(!a[p+1][q]&&p<n-1&&q>=0)
            a[++p][q]=d--;
        while(!a[p][q-1]&&p>=0&&q>=1)
            a[p][--q]=d--;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%4.d",a[i][j]);
        cout<<endl;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);  //重定向直接在文件中读入数据
    int n;
    cin>>n;
    f1(n);
    cout<<endl;
    f2(n);
    return 0;
}
