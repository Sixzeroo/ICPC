#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;

int dp[200005];

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int a[7],o=1,i,j,sum;
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6])
    {
        sum=0;
        for(i=1;i<=6;i++)
            sum+=a[i]*i;
        if(!sum)
            break;
        cout<<"\nCollection #"<<o++<<":"<<endl;
        if(sum%2)
            cout<<"Can't be divided."<<endl;
        else
        {
            sum/=2;
            memset(dp,-1,sizeof(dp));
            dp[0]=0;
            for(i=1;i<=6;i++)
                for(j=0;j<=sum;j++)
                {
                    if(dp[j]>=0)dp[j]=a[i];   //之前已经配好j
                    else if(i>j||dp[j-i]<=0) dp[j]=-1;  //不能配或者没有物品了
                    else dp[j]=dp[j-i]-1;  //差一个
                }
            if(dp[sum]>=0)
                cout<<"Can be divided."<<endl;
            else
                cout<<"Can't be divided."<<endl;
        }
    }
    return 0;
}
