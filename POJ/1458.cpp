#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
const int mod=1e9+7;
const int maxn=1005;
const int maxm=10005; 

int dp[maxn][maxn];

int LCS(string a,string b) {
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<a.length(); ++i)  // a
		for(int j=0; j<b.length(); ++j) { // b
			if(a[i] == b[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	return dp[a.length()][b.length()];
}

/*void solve()
{
	char A[maxn],B[maxn];
    while(scanf("%s %s",A,B)!=EOF)
	{
		int a=strlen(A),b=strlen(B);
		int ans=LCS(A,B,a,b);
		printf("%d\n",ans);
	}
}
*/

void solve()
{
	string a,b;
	while(cin>>a>>b)
	{
		cout<<LCS(a,b)<<endl;
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	solve();
	return 0;
}

