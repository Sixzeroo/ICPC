#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

char ch[55];

void solve()
{
	for(int i=0;i<26;i++)
	{
		ch[i]='a'+i;
		ch[i+26]='A'+i;
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	   printf("2 %d %d\n",n,n);
	   for(int i=0;i<n;i++)
       {
	    	for(int j=0;j<n;j++)
	    	{
	    		printf("%c",ch[i]);
	     	}
			printf("\n");
       }
       printf("\n");
	   for(int i=0;i<n;i++)
	   {
	    	for(int j=0;j<n;j++)
	     	{
	    		printf("%c",ch[j]);
	    	} 
            printf("\n");
       }
	}
}

int main()
{
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
