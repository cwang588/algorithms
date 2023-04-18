#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100050],b[100050],c[100050];
char s[100050];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(s,0,sizeof(s));
		cin>>(s+1);
		int plus=0,flg=1;
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			if(s[i]=='+'&&plus) flg=false;
			if(s[i]=='+') plus=i;
			if(s[i]!='+'&&(s[i]<'0'||s[i]>'9')) flg=false;
		}
		if(plus==1||plus==len||!plus) flg=false;
		if(flg==false)
		{
			printf("skipped\n");
			continue;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int alen=0,blen=0;
		for(int i=plus-1;i;i--) a[++alen]=(int)(s[i]-'0');
		for(int i=len;i>plus;i--) b[++blen]=(int)(s[i]-'0');
		len=max(alen,blen);
		for(int i=1;i<=len;i++) c[i]=a[i]+b[i];
		for(int i=1;i<=len;i++)
		{
			if(c[i]>=10)
			{
				c[i+1]+=c[i]/10;
				c[i]%=10;
				if(i==len) len++;
			}
		}
		for(int i=len;i;i--) printf("%d",c[i]);
		printf("\n");
	}
}
