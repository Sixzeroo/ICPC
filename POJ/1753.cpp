#include <iostream>
#include <cstdio>
#include<cstring>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
#include<map>

#define in(a) scanf("%d",&a)

using namespace std;

int pan[6][6];
int c=33;    //存放最后的结果

void turn(int x,int y)
{
    pan[x-1][y]=!pan[x-1][y];
    pan[x+1][y]=!pan[x+1][y];
    pan[x][y-1]=!pan[x][y-1];
    pan[x][y+1]=!pan[x][y+1];
    pan[x][y]=!pan[x][y];
}

bool judge()
{
    int tem=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            tem+=pan[i][j];
    if(tem%16==0)
        return true;
    else
        return false;
}

void dfs(int s,int d)  //  s表示遍历到的格子，d表示已经翻转的格子
{
    if(judge())
    {
        if(c>d)
            c=d;
        return;
    }
    if(s>=16)
        return;
    dfs(s+1,d);
    turn(s/4+1,s%4+1);
    dfs(s+1,d+1);
    turn(s/4+1,s%4+1);     //枚举之后回到之前的状态

}

void solve()
{
    char ch;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            cin>>ch;     //使用getchar和scanf都不能舍弃最后的回车符
            if(ch=='w')
                pan[i][j]=1;
            else
                pan[i][j]=0;
        }
    dfs(0,0);
    if(c!=33)
        printf("%d\n",c);
    else
        printf("Impossible");
}

int main()
{
    freopen("input.txt","r",stdin);
    solve();
    return 0;
}
