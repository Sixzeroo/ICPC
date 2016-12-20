#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;
#define SIZE 3005
#define INF 0x3f3f3f3f

bool is_prime[SIZE];

void init_pri()
{
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;

    for(int i=2;i<SIZE;i++)
    {
        if(is_prime[i])
        {
            for(int j=2*i;j<SIZE;j+=i)
                is_prime[j]=false;
        }
    }
}

bool comput(int x,int y)
{
    for(int i=x;i<=y;i++)
    {
        int n=i*i+i+41;
        if(!is_prime[n])
            return false;
    }
    return true;
}

void solve()
{
    init_pri();
    int x,y;
    while(scanf(("%d %d"),&x,&y)!=EOF)
    {
        if(x==0&&y==0)
            return;
        if(comput(x,y))
            cout<<"OK"<<endl;
        else
            cout<<"Sorry"<<endl;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
