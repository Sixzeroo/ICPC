#include<stdio.h>
#include<iostream>
#include<sstream>
#include<cstring>

using namespace std;
#define mm(a) memset(a,1,sizeof(a))
char b[101][101];
int n,m;
int ans;

void dfs(int a,int d)
{
    b[a][d]='.';
    int x,y,dx,dy;
    for(dx=-1;dx<2;dx++)
        for(dy=-1;dy<2;dy++)
        {
            x=a+dx;
            y=d+dy;
            if(x>0&&x<=n&&y>0&&y<=m&&b[x][y]=='W')
                dfs(x,y);
        }
    return;
}

void solve()
{
    ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>b[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]=='W')
            {
                dfs(i,j);
                ans++;
            }
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
