#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;
#define MAXSIZE 100005
#define in(a) scanf("%d",&a)

void solve()
{
    int n,A=0,D=0;
    while(cin>>n)
    {
        A=0;
        D=0;
        string a;
        cin>>a;
        for(int i=0;i<n;i++)
            if(a[i]=='A')A++;
            else D++;
        if(A>D)cout<<"Anton"<<endl;
        else if(A<D)cout<<"Danik"<<endl;
        else
            cout<<"Friendship"<<endl;
    }

}

int main()
{
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}