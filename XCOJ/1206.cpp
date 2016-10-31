#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<sstream>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<algorithm>
#include<set>
#include<functional>
#include<stack>
#include<iterator>

using namespace std;

void solve()
{
    long long n,k;
    cin>>n>>k;
    long long ans,a,b;
    a=n%k;
    b=n/k;
    if(b%2==0)
        ans=k*k*b/2-(b*k+1+n)*a/2;
    else
        ans=k*k*(b-1)/2-((2*b-1)*k+1)*k/2+(b*k+1+n)*a/2;
    cout<<ans<<endl;
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
