#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int t,n,a[maxn],Left[maxn],Right[maxn],Min[maxn];

// 初始化确定左右两边的值
void init()
{
    scanf("%d",&n);
    Left[0]=1;
    Right[n-1]=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i)
        {
            Left[i]=1;
            if(a[i]>a[i-1]) Left[i]+=Left[i-1];
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        Right[i]=1;
        if(a[i]<a[i+1]) Right[i]+=Right[i+1];
    }

}

int fun()
{
    int ans=0;
    memset(Min,INF,sizeof(Min));
    for(int i=0;i<n;i++)
    {
        int len=lower_bound(Min+1,Min+1+n,a[i])-Min;  //根据元素值得到最小延伸值
        ans=max(ans,Right[i]+len-1);
        Min[Left[i]]=min(Min[Left[i]],a[i]);   //更新延伸值对应的元素值 
    }
    return ans;
}

void solve()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        printf("%d\n",fun());
    }
}

int main()

{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
