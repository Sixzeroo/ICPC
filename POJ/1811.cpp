#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <utility>

using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

//Miller_Rabin 算法进行素数测试
//速度快，而且可以判断 <2^63的数

const int S=20; //随机算法判定次数

//计算 (a*b)%c  加法快速幂
ll mul_mod(ll a,ll b,ll c)
{
	a%=c;
	b%=c;
	ll ret=0;
	while(b)
	{
		if(b&1)
			ret+=a,ret%=c;
		a<<=1;
		if(a>=c)a%=c;
		b>>=1;
	}
	return ret;
}

// 计算x^n %c
ll pow_mod(ll x,ll n,ll mod)
{
	if(n==1) return x%mod;
	x%=mod;
	ll tmp=x;
	ll ret=1;
	while(n)
	{
		if(n&1) ret=mul_mod(ret,tmp,mod);
		tmp=mul_mod(tmp,tmp,mod);
		n>>=1;
	}
	return ret;
}

//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(ll a,ll n,ll x,ll t)
{
	ll ret=pow_mod(a,x,n);
	ll last=ret;
	for(int i=1;i<=t;i++)
	{
		ret=mul_mod(ret,ret,n);
		if(ret==1 && last!=1 && last!=n-1) return true;
		last=ret;
	}
	if(ret!=1) return true;
	return false;
}

// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;
bool Miller_Rabin(ll n)
{
	if(n<2) return false;
	if(n==2) return true;
	if((n&1)==0) return false;   //偶数
	ll x=n-1,t=0;
	while(!(x&1)) 
	{
		x>>=1;
		t++;
	}
	for(int i=0;i<S;i++)
	{
		ll a=rand()%(n-1)+1;
		if(check(a,n,x,t))
			return false;
	}
	return true;
}


// pollard_rho 算法进行质因数分解
ll factor[100];   //分解结果
int tol;    //分解个数

ll gcd(ll a,ll b)
{
	if(a==0) return 1;
	if(a<0) return gcd(-a,b);
	return b==0?a:gcd(b,a%b);
}

ll Pollard_rho(ll x,ll c)
{
	ll i=1,k=2;
	ll x0=rand()%x;
	ll y=x0;
	while(1)
	{
		i++;
        x0=(mul_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
	}
}

//对n进行素因子分解
void findfac(ll n)
{
	if(Miller_Rabin(n))
	{
		factor[tol++]=n;
		return;
	}
	ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

void solve()
{
	int t;
	ll n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(Miller_Rabin(n))
		{
			printf("Prime\n");
			continue;
		}
		tol=0;
		findfac(n);
		ll ans=factor[0];
		for(int i=1;i<tol;i++)
			ans=min(ans,factor[i]);
		printf("%lld\n",ans);
	}
}

int main() 
{
    freopen("input.txt","r",stdin);

    //test();
    solve();
    return 0;
}
