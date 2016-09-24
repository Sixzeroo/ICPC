#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;

int A[4005];
int t,i;
int n,m,q,j,d,tem;

int main()
{
    freopen("input.txt","r",stdin);
    //std::ios::sync_with_stdio(false);

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        //cin>>n>>m>>q;
        j=n*m;
        for(i=0;i<j;i++)
            scanf("%d",&A[i]);
            //cin>>A[i];
        sort(A,A+j);
        while(q--)
        {
            scanf("%d",&d);
            //cin>>d;
            tem=upper_bound(A,A+j,d)-A;
            printf("%d\n",j-tem);
            //cout<<j-tem<<endl;
        }
    }
    return 0;
}
