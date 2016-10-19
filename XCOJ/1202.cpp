#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>
#include<utility>

using namespace std;
const double k=(sqrt(5)-1.0)/2.0;

void solve()
{
    double n;
    long t;
    while(cin>>n)
    {
        t=int(k*n+0.5);
        cout<<t<<endl;
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
