#include <iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<ctime>
#include<stack>

using namespace std;

struct BigInt
{
    const static int nlen=4;  //���������е�ÿһ�����ֵĳ��ȣ�Ϊ�˳˷����㲻����趨Ϊ4
    const static int mod=10000;    //ÿ�����ִ�С�趨
    short n[1000],len;  //������ֵ������Լ�����ĳ���
    BigInt()//û�и�ֵʱ��ʼ��Ϊ0
    {
        memset(n,0,sizeof(n));
        len=1;
    }
    BigInt(int num)//����Ϊ�丳ֵʱ��������4λ4λ��������鵱��
    {
        len=0;
        while(num>0)
        {
            n[len++]=num%mod;
            num/=mod;
        }
    }
    BigInt(const char *s)  //�ַ�����ֵʱ
    {
        int l=strlen(s);
        len=l%nlen==0?l/nlen:l/nlen+1;//ȷ�����鳤��
        int index=0;
        for(int i=l-1;i>=0;i-=nlen)//ÿ�δ��������е�һλ
        {
            int tmp=0;
            int j=i-nlen+1;
            if(j<0) j=0;//��������ֵĴ���
            for(int k=j;k<=i;k++)
                tmp=tmp*10+s[k]-'0';
            n[index++]=tmp;
        }
    }
    BigInt operator+(const BigInt &b)const //�ӷ�����
    {
        BigInt res;
        res.len=max(len,b.len);  //ȷ��λ��
        for(int i=0;i<res.len;++i)
        {
            res.n[i]+=(i<len?n[i]:0)+(i<b.len?b.n[i]:0); //����λ�����
            res.n[i+1]+=res.n[i]/mod; //��λ����
            res.n[i]=res.n[i]%mod;
        }
        if(res.n[res.len]>0)++res.len;  //���Ľ�����һλʱ
        return res;
    }
    BigInt operator*(const BigInt &b)const  //�˷�����
    {
        BigInt res;
        for(int i=0;i<len;i++)  //ģ�����
        {
            int up=0;  //��λ�洢
            for(int j=0;j<b.len;j++)
            {
                int tmp=n[i]*b.n[i]+up+res.n[i+j];
                res.n[i+j]=tmp%mod;
                up=tmp/mod;
            }
            if(up!=0)  //����һ���Ժ��н�λ
                res.n[i+b.len]=up;
        }
        res.len=len+b.len;  //��ȡ��λ����������ֵ
        while(res.n[res.len-1]==0&&res.len>1)res.len--;
        return res;
    }
    void show() const  //���ʱ���������
    {
        printf("%d",n[len-1]);
        for(int i=len-2;i>=0;i--)
            printf("%04d",n[i]);
        printf("\n");
    }
};

typedef struct BigInt bb;

bb sz[10005];

void init()
{
    sz[1]=sz[2]=1;
    for(int i=3;i<=10000;i++)
        sz[i]=sz[i-1]+sz[i-2];
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    int n;
    init();
    while(cin>>n)
        sz[n].show();
    return 0;
}
