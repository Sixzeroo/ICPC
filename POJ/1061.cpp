#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

#define LL long long

using namespace std;


LL e_gcd(LL a,LL b,LL &x,LL &y)
{
    LL d=a;
    if(!b)
    {
        x=1;
        y=0;
    }
    else
    {
        d=e_gcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    return d;
}

LL solve(LL a,LL b,LL c)  //ʹ����չŷ������㷨
{
    LL e,x,y;
    e=e_gcd(a,b,x,y);
    if(c%e!=0)return -1;
    x*=c/e;
    b/=e;
    if(b<0)b=-b;
    LL ans=x%b;  //ȡ����С��������
    if(ans<0)
        ans+=b;  //Ϊ��ȡ����С��������
    return ans;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    LL m,n,L,x,y;
    while(cin>>x>>y>>m>>n>>L)
    {
        LL ans=solve(m-n,L,y-x);
        if(ans==-1)
        {
            cout<<"Impossible"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
    }
    return 0;
}
