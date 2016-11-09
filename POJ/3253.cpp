#include<stdio.h>
#include<iostream>
#include<sstream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int n;
long long ans;

void solve()
{
    ans=0;
    priority_queue<int,vector<int>,greater<int> > p;
    cin>>n;
    int i,x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        p.push(x);
    }
    while(p.size()!=1)
    {
        x=0;
        x+=p.top();
        p.pop();
        x+=p.top();
        p.pop();
        p.push(x);
        ans+=x;
    }
    cout<<ans<<endl;

}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
