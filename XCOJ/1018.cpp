#include <iostream>
#include<queue>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;


void solve()
{
    int y,yd,m,res[7],num=13,biao;
    memset(res,0,sizeof(res));
    cin>>yd;
    y=1900;
    yd+=y;
    while(y<yd)
    {
        if((y%4==0&&y%100!=0)||(y%400==0))
            biao=1;
        else
            biao=0;
        for(m=1;m<=12;m++)
        {
            res[num%7]++;
            if(m==2)
                if(biao)
                    num+=29;
                else
                    num+=28;
            else if(m==4||m==6||m==11||m==9)
                num+=30;
            else
                num+=31;
        }
        y++;
    }
    cout<<res[6]<<" "<<res[0]<<" "<<res[1]<<" "<<res[2]<<" "<<res[3]<<" "<<res[4]<<" "<<res[5]<<endl;
}

int main()
{
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
