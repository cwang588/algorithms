#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int a[10005],b[10005],c[10005];
char t[50005];
int main()
{
	while(cin>>t)
	{
		bool qh=false;
		int fg;
		for(int i=0;i<strlen(t);++i)
		{
			if(t[i]=='-')
			{
				qh=true;
				continue;
				fg=i;
			}
			if(!qh&&t[i]!=' ')
				a[i+1]=t[i];
			if(qh&&t[i]!=' ')
				b[i-fg-1]=t[i];
		}
		a[0]=fg;
		for(int i=1;i<=a[0];++i)
			a[i]=t[a[0]-i]-'0';
		b[0]=strlen(t)-fg;
		for(int i=1;i<=b[0];++i)
			b[i]=t[b[0]-i]-'0';
		bool fu=false;
		if(a[0]<b[0])
			fu=true;
		else if(a[0]==b[0])
		{
			for(int i=a[0];i>=1;--i)
			{
				if(a[i]<b[i])
				{
					fu=true;
					break;
				}
				else if(a[i]==b[i])
					continue;
				else
					break;
			}
		}
		if(fu)
			for(int i=b[0];i>=0;--i)
				swap(a[i],b[i]);
		for(int i=1;i<=a[0];++i)
		{
			c[i]+=(a[i]-b[i]);
			if(c[i]<0)
			{
				c[i]+=10;
				--c[i+1];
			}
		}
		for(int i=a[0];i>=1;--i)
			if(c[i])
			{
				c[0]=i;
				break;
			}
		if(fu)
			printf("-");
		for(int i=c[0];i>=1;--i)
			printf("%d",c[i]);
		if(!c[0])
			printf("0");
		memset(a,' ',sizeof(a));
		memset(b,' ',sizeof(b));
		memset(c,' ',sizeof(c));
		memset(t,' ',sizeof(t));
	}
	return 0;
}
