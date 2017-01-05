#include <iostream>
#include<string>
#include<cstdio>
using namespace std;

void solve()
{
	int p,e,i,d,ca=1;
	while(cin>>p>>e>>i>>d)
	{
		if(p==-1)
			break;
		long long x=(5544*p+14421*e+1288*i-d+21252)%21252;
		if(x==0)x=21252;
		printf("Case %d: the next triple peak occurs in %lld days.\n",ca,x);
		ca++;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	solve();
    return 0;
}

