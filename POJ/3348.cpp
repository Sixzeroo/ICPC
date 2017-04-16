#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int maxn=10005;

struct point
{
	double x,y;
}p[maxn],t[maxn];
int n;    //点的个数

//得到相应的叉乘
double get_X(point a,point b,point c)        //ab到ac的叉乘计算
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double len(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(point &a,point &b)
{
	double pp=get_X(p[0],a,b);
	if(pp>0) return true;
	if(pp<0) return false;
	return len(p[0],a)<len(p[0],b);
}

int Graham()     //返回凸包所含有的点的个数
{
	if(n<=2) return 0;
	else
	{
		for(int i=1;i<n;i++)     //找到起始点
		{
			if(p[i].x<p[0].x) swap(p[i],p[0]);
			else if(p[i].x==p[0].x && p[i].y<p[0].y) swap(p[i],p[0]);
		}
		sort(p+1,p+n,cmp);
		t[0]=p[0];
		t[1]=p[1];
		int top=1;    //栈顶位置
		for(int i=2;i<n;i++)
		{
			while(t>0 && get_X(t[top-1],t[top],p[i])<=0) top--;    //考虑的点在右侧的时候将栈顶的点弹出
			top++;
			t[top]=p[i];
		}
		return top;
	}
}

void solve()
{
	while(scanf("%d",&n)!=EOF) {
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		int num = Graham();
		if (num == 0) printf("0\n");
		else
		{
			int ans = 0;
			for (int i = 1; i < num; i++)
				ans += fabs(get_X(t[0], t[i], t[i + 1])) / 2.0;
			printf("%d\n", ans/50);
		}
	}
}


int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
