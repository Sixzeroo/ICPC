#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define in(a) scanf("%d",&a)

using namespace std;
#define INF 0x3f3f3f3f

const int maxn=1e6+6;

struct Q
{
	int x;
	int id;
};

Q q[maxn];     //单调队列定义
int a[maxn];

void solve()
{
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int h=1,r=0;     //h表示队头  r表示队尾
		//初始化队列
		for(int i=0;i<maxn;i++)
			q[i].id=maxn;
		//加入初始的k个值
		for(int i=1;i<=k;i++)
		{
			//保证队列中的元素是递增的
			while(r>=h && q[r].x>a[i]) r--;
            q[++r].x=a[i];   //入队
			q[r].id=i;
		}
		for(int i=k+1;i<=n;i++)  //向后递推的过程
		{
			printf("%d ",q[h].x);    //第一个元素一定是最小的
			while(q[h].id<=i-k) h++;     //当第一个元素步子范围内的时候，进行删除
			while(r>=h && q[r].x>a[i]) r--;   //维护队列的单调性
			q[++r].x=a[i];
			q[r].id=i;
		}
	    printf("%d\n",q[h].x);
		//再来一遍求最大值
		for(int i=0;i<maxn;i++) q[i].id=maxn;
		h=1,r=0;
		for(int i=1;i<=k;i++)
		{
			while(r>=h && q[r].x<a[i]) r--;
			q[++r].x=a[i];
			q[r].id=i;
		}
		for(int i=k+1;i<=n;i++)
		{
			printf("%d ",q[h].x);
			while(q[h].id<=i-k) h++;
			while(r>=h && q[r].x<a[i]) r--;
			q[++r].x= a[i];
			q[r].id=i;
		}
		printf("%d\n",q[h].x);
	}
}


int main()                         
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
