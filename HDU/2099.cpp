#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
#define INF 0x3f3f3f3f
const int maxn=100005;

void solve()
{
	int a,b;
	int mi,ma;
	bool flag;   //判断空格
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		flag=0;
		if(a==0&&b==0)
			break;
		mi=(100*a-1)/b;
		ma=(100*(a+1))/b;
		for(int i=mi+1;i<=ma;i++)
		{
			if(i*b<(100*(a+1)) && i*b>=(100*a))
			{
				if(flag) printf(" ");
				int tmp=i*b%100;
				if(tmp<10)
					printf("0");
				printf("%d",tmp);
				flag=1;
			}
		}
		printf("\n");
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
