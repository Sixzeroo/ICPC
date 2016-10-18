#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>
#include<utility>

using namespace std;
#define in(a,b) scanf("%d%d",&a,&b)

int bit[1000005],N;

//树状数组求和
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)  //添加元素
{
    while(i<=N)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}

void solve()
{
    int m,q,p,t,j,k,i;
    while(in(m,q)!=EOF)
    {
        memset(bit,0,sizeof(bit));
        for(i=0;i<m;i++)
        {
            in(p,t);
            add(t+1,p);  //加1处理，与树状数组相匹配
        }
        for(i=0;i<q;i++)
        {
            in(j,k);
            printf("%d\n",sum(k+1)-sum(j));
        }
    }


}


int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    N=1000002;
    solve();
    return 0;
}
