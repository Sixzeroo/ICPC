#include<iostream>  
#include<algorithm>  
#include<string.h>  
#include<stdio.h>  
#include<stack>  
using namespace std;  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
		string s1,s2,s3;  
		int len1,len2,len3;  
		cin>>s1>>s2;  
		int pos1,pos2;  
		pos1=s1.find("."),pos2=s2.find(".");  
		len1=s1.size(),len2=s2.size();
		
		if(pos1==-1)  //小数扩展到1000位
		{  
			pos1=s1.size();  
			s1+='.';  
			for(int i=0;i<1000;i++)  
				s1+='a';  
		}  
		else  
		{  
			int ls1=s1.size();  
			for(int i=ls1;s1.size()-pos1<=1000;i++)  
				s1+='a';  
		}  
	  
		if(pos2==-1)  
		{  
			pos2=s2.size();  
			s2+='.';  
			for(int i=0;i<1000;i++)  
				s2+='a';  
		}  
		else  
		{  
			int ls2=s2.size();  
			for(int i=ls2;s2.size()-pos2<=1000;i++)  
				s2+='a';  
		} 
		
		int carry=0;  
		len1=s1.size(),len2=s2.size();  
		int ans[2500];  
		int cnt=0;  
		for(int i=len1-1,j=len2-1;i>pos1&&j>pos2;i--,j--)  
			{  
				ans[cnt++]=(s1[i]-'a'+s2[j]-'a'+carry)%26;  
				carry=(s1[i]-'a'+s2[j]-'a'+carry)/26;  //进位记录
			}  
		 ans[cnt++]=-1;  //小数点标记
		 
		 stack<char>S1,S2;    //使用栈进行整数部分加法操作
		 for(int i=0;i<pos1;i++)  
			S1.push(s1[i]);  
		 for(int i=0;i<pos2;i++)  
			S2.push(s2[i]);  
		 while(!S1.empty()||!S2.empty())  
		 {  
			 char a;  
			 if(!S1.empty())  
				{  
					a=S1.top();  
					S1.pop();  
				}  
			 else a='a';  
	  
			 char b;  
			 if(!S2.empty())  
				{  
					b=S2.top();  
					S2.pop();  
				}  
			 else b='a';  
			 ans[cnt++]=(a-'a'+b-'a'+carry)%26;  
			 carry=(a-'a'+b-'a'+carry)/26;  
		 }  
		 ans[cnt++]=carry;
		 
		 for(int i=cnt-1;i>=0;i--)  //整数部分处理
			if(ans[i]!=-1)  
				s3+=(char)(ans[i]+97);  
			else {  
				s3+='.';  
				continue;  
			}
			
		 int pos=s3.find(".");  
		 for(int i=0;i<=pos;i++)  
			if(s3[i]=='a')  
				continue;  
			else  
			{  
				 pos1=i;  
				 break;  
			}  
		 for(int i=s3.size()-3;i>=pos;i--)  
			if(s3[i]=='a')  
				continue;  
			else {  
				pos2=i;  
				break;  
			}  
		 if(pos1==pos&&pos==pos2)  
		 {  
			 cout<<"a"<<endl;  
		 }  
		 else if(pos1==pos&&pos2>pos)  
		 {  
			 cout<<"a";  
			 for(int i=pos;i<=pos2;i++)  
				cout<<s3[i];  
			 cout<<endl;  
		 }  
		 else if(pos1<pos&&pos2==pos)  
		 {  
			 for(int i=pos1;i<pos;i++)  
				cout<<s3[i];  
			 cout<<endl;  
		 }  
		 else if(pos1<pos&&pos2>pos)  
		 {  
			 for(int i=pos1;i<=pos2;i++)  
				cout<<s3[i];  
			 cout<<endl;  
		 }  
    }  
    return 0;  
}  