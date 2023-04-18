#include<bits/stdc++.h>
using namespace std;
struct net
{
	int a,b,c,d;
	bool operator < (const net &x)const
	{
		if(a!=x.a)return a<x.a;
		if(b!=x.b)return b<x.b;
		if(c!=x.c)return c<x.c;
		return d<x.d;
	} 
}nn;
map<net,int>mm;
char s[55];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		memset(s,0,sizeof(s));
		int x;
		cin>>x>>(s+1);
		int l=strlen(s+1);
		int a,b,c,d,e,now;
		a=b=c=d=e=now=0;
		for(int i=1;i<=l;++i)
		{
			if(s[i]=='.')
			{
				now=i+1;
				break;
			}
			a=a*10+s[i]-'0';
		}
		for(int i=now;i<=l;++i)
		{
			if(s[i]=='.')
			{
				now=i+1;
				break;
			}
			b=b*10+s[i]-'0';
		}
		for(int i=now;i<=l;++i)
		{
			if(s[i]=='.')
			{
				now=i+1;
				break;
			}
			c=c*10+s[i]-'0';
		}
		for(int i=now;i<=l;++i)
		{
			if(s[i]=='/')
			{
				now=i+1;
				break;
			}
			d=d*10+s[i]-'0';
		}
		for(int i=now;i<=l;++i)
			e=e*10+s[i]-'0';
		for(int i=d;i<=e+d;++i)
		{
			net tt;
			tt.a=a;
			tt.b=b;
			tt.c=c;
			tt.d=i;
			mm[tt]=x;
		}
	}
	for(int i=1;i<=m;++i)
	{
		memset(s,0,sizeof(s));
		cin>>(s+1);
		int l=strlen(s+1);
		int a,b,c,d,now;
		a=b=c=d=now=0;
		for(int i=1;i<=l;++i)
		{
			if(s[i]=='.')
			{
				now=i+1;
				break;
			}
			a=a*10+s[i]-'0';
		}
		for(int i=now;i<=l;++i)
		{
			if(s[i]=='.')
			{
				now=i+1;
				break;
			}
			b=b*10+s[i]-'0';
		}
		for(int i=now;i<=l;++i)
		{
			if(s[i]=='.')
			{
				now=i+1;
				break;
			}
			c=c*10+s[i]-'0';
		}
		for(int i=now;i<=l;++i)
			d=d*10+s[i]-'0';
		net tt;
		tt.a=a;
		tt.b=b;
		tt.c=c;
		tt.d=d;
		printf("%d\n",mm[tt]>0?mm[tt]:-1);
	}
	return 0;
}
