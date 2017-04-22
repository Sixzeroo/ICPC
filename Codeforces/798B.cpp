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

int n,len;
char s[51][101];

bool judge(char *a,char *b) //判断以a b两个字符串是否相等
{
	for(int i=0;i<len;i++)
		if(a[i]!=b[i]) return false;
	return true;
}

void solve()
{
	while(scanf("%d",&n)!=EOF)
	{
		bool flag=false;
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		len=strlen(s[0]);  
		for(int i=0;i<n;i++)
			for(int j=0;j<len;j++)
				s[i][j+len]=s[i][j];     //在原来的字符串后面加上相同的字符串
		int res=0,ans=INF;
		for(int i=0;i<n;i++)
		{
			res=0;
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				int k;
				for(k=0;k<len;k++)
					if(s[i][0]==s[j][k] && judge(s[i],s[i]+k))   //j串循环左移k位
					{
						res+=k;
						break;
					}
				if(k==len)
				{
					printf("-1\n");
					flag=1;
					break;
				}
			}
			if(flag)
				break;
			ans=min(ans,res);
		}
        if(flag) break;
		printf("%d\n",ans);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
