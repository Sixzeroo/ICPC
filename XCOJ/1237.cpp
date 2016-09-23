#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;



void solve()
{
    priority_queue<long long> p;
    long long n,i,k,d;
    cin>>n;
    for(i=0;i<n;i++) //输入元素
    {
        cin>>d;
        p.push(d);
    }
    cin>>k;
    for(int i=0;i<k-1;i++)  //输出对应的排序元素
    {
        d=p.top();
        while(d==p.top())
        {
            p.pop();
        }
    }
    cout<<p.top()<<endl;

}

int main()
{
    //freopen("input.txt","r",stdin);
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}
