#include<iostream>
#include<cstdio>   //ʹ���ļ��ض�������
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[17];
bool bused[20];   //�ж϶�Ӧ��������û�б�ʹ��

//��ʽ����ɸѡ��
#define MAXL 101
bool isprime[MAXL];
void init_pri(void)
{
    int i,j;
    memset(isprime,1,sizeof(isprime));
    for(i=2;i<MAXL;i++)
    {
        if(isprime[i])
            for(j=2*i;j<MAXL;j+=i)
                isprime[j]=0;
    }
    return;
}

void AA(int cur)
{
    int i;
    if(cur==n&&isprime[a[0]+a[n-1]])//���ݷ��ĵݹ�߽磬��n-1�������ʱ��������������е�Ԫ�ض������
    {
        cout<<1;
        for(i=1;i<n;i++)cout<<" "<<a[i];
        cout<<endl;
        return;
    }
    else if(cur<n)
    {
        for(i=2;i<=n;i++)
            if(!bused[i]&&isprime[a[cur-1]+i])
            {
                a[cur]=i;
                bused[i]=1;   //��Ǳ��ù�
                AA(cur+1);
                bused[i]=0;   //��������һ����ʱ���±��
            }
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);  //�ض���ֱ�����ļ��ж�������
    int d=0;
    init_pri();
    //for(int i=0;i<MAXL;i++)
        //if(isprime[i])cout<<i<<endl;
    while(cin>>n)
    {
        cout<<"Case "<<++d<<":"<<endl;
        memset(bused,0,sizeof(bused));
        a[0]=1;
        AA(1);
        cout<<endl;
    }
    return 0;
}
