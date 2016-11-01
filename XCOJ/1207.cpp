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

#define SIZE 1005
pair<int,int> p[SIZE];
int n;

void solve()
{
    set<double> se;
    se.clear();
    double k;
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].first!=p[j].first)
                k=(p[i].second-p[j].second)*1.0/(p[i].first-p[j].first)*1.0;
            se.insert(k);
        }
    }
    cout<<se.size()<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
