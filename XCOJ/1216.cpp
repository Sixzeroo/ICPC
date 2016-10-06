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
    const static int nlen=4;  //控制数组中的每一个数字的长度，为了乘法运算不溢出设定为4
    const static int mod=10000;    //每个数字大小设定
    short n[1000],len;  //存放数字的数组以及数组的长度
    BigInt()//没有赋值时初始化为0
    {
        memset(n,0,sizeof(n));
        len=1;
    }
    BigInt(int num)//数字为其赋值时，将数字4位4位存放在数组当中
    {
        len=0;
        while(num>0)
        {
            n[len++]=num%mod;
            num/=mod;
        }
    }
    BigInt(const char *s)  //字符串赋值时
    {
        int l=strlen(s);
        len=l%nlen==0?l/nlen:l/nlen+1;//确定数组长度
        int index=0;
        for(int i=l-1;i>=0;i-=nlen)//每次处理数组中的一位
        {
            int tmp=0;
            int j=i-nlen+1;
            if(j<0) j=0;//最后面数字的处理
            for(int k=j;k<=i;k++)
                tmp=tmp*10+s[k]-'0';
            n[index++]=tmp;
        }
    }
    BigInt operator+(const BigInt &b)const //加法操作
    {
        BigInt res;
        res.len=max(len,b.len);  //确定位数
        for(int i=0;i<res.len;++i)
        {
            res.n[i]+=(i<len?n[i]:0)+(i<b.len?b.n[i]:0); //对象位置相加
            res.n[i+1]+=res.n[i]/mod; //进位处理
            res.n[i]=res.n[i]%mod;
        }
        if(res.n[res.len]>0)++res.len;  //最后的结果多出一位时
        return res;
    }
    BigInt operator*(const BigInt &b)const  //乘法操作
    {
        BigInt res;
        for(int i=0;i<len;i++)  //模拟过程
        {
            int up=0;  //进位存储
            for(int j=0;j<b.len;j++)
            {
                int tmp=n[i]*b.n[i]+up+res.n[i+j];
                res.n[i+j]=tmp%mod;
                up=tmp/mod;
            }
            if(up!=0)  //处理一遍以后还有进位
                res.n[i+b.len]=up;
        }
        res.len=len+b.len;  //先取到位数可能最大的值
        while(res.n[res.len-1]==0&&res.len>1)res.len--;
        return res;
    }
    void show() const  //输出时的逆序输出
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
