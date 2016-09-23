#include<iostream>
#include<cstdio>   //使用文件重定向输入
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[17];
bool bused[20];   //判断对应的数字有没有被使用

//埃式素数筛选法
#define MAXL 101
bool isprime[MAXL];
void init_pri(void)
{
    int i,j;
    memset(isprime,1,sizeof(isprime));
    for(i=2;i<MAXL;i++)
    {
        if(isprime[i])
            for(j=2*i;j<MAXL;j+=i)
                isprime[j]=0;
    }
    return;
}

void AA(int cur)
{
    int i;
    if(cur==n&&isprime[a[0]+a[n-1]])//回溯法的递归边界，当n-1完成填充的时候代表数组中所有的元素都填充满
    {
        cout<<1;
        for(i=1;i<n;i++)cout<<" "<<a[i];
        cout<<endl;
        return;
    }
    else if(cur<n)
    {
        for(i=2;i<=n;i++)
            if(!bused[i]&&isprime[a[cur-1]+i])
            {
                a[cur]=i;
                bused[i]=1;   //标记被用过
                AA(cur+1);
                bused[i]=0;   //考虑另外一个数时更新标记
            }
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);  //重定向直接在文件中读入数据
    int d=0;
    init_pri();
    //for(int i=0;i<MAXL;i++)
        //if(isprime[i])cout<<i<<endl;
    while(cin>>n)
    {
        cout<<"Case "<<++d<<":"<<endl;
        memset(bused,0,sizeof(bused));
        a[0]=1;
        AA(1);
        cout<<endl;
    }
    return 0;
}
