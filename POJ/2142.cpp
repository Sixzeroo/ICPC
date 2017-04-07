#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//扩展欧几里得
int e_gcd(int a,int b,int &x,int &y)
{
	int d=a;
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

void solve()
{
	int a,b,d,x,y;
	bool flag;
	while(scanf("%d %d %d",&a,&b,&d)!=EOF)
	{
		if(!a && !b &&!d)
			break;
		if(a<b)
		{
			swap(a,b);
			flag=1;
		}
		else
			flag=0;
		int g=e_gcd(a,b,x,y);
		int t=d/g,t1=b/g,t2=a/g;
		x*=t;
		y*=t;
		int i=y/t2;
		if(y-i*t2<0)i--;
		int x1=abs(x+t1*i),y1=abs(y-t2*i),tmp1=x1+y1,ans1=a*x1+b*y1;
		i++;
		int x2=abs(x+t1*i),y2=abs(y-t2*i),tmp2=x2+y2,ans2=a*x2+b*y2;
		if(tmp1>tmp2)
		{
			x=x2;
			y=y2;
		}
		else if(tmp1 < tmp2) x=x1,y=y1;
		else
		{
			if(ans1<ans2) x=x1,y=y1;
			else
				x=x2,y=y2;
		}
		if(flag)printf("%d %d\n",y,x);
		else printf("%d %d\n",x,y);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
