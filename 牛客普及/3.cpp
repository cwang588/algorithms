#include<cstdio>
#include<iostream>
#include<cstring>
#define p 233
using namespace std;
char a[2000005],b[1000005],c[1000005];
unsigned long long mi[1000005]={1};
unsigned long long ksm(unsigned long long x)
{
	if(mi[x])
		return mi[x];
	if(x%2)
		mi[x]=ksm(x/2)*ksm(x/2)*p;
	else
		mi[x]=ksm(x/2)*ksm(x/2);
	return mi[x];	
}
int main()
{
	cin>>a;
	cin>>b;
	cin>>c;
	unsigned long long ha=0,h=0,L=strlen(a),l=strlen(b);
	for(int i=l-1;i>=0;--i)
		ha=ha*p+b[i];
	for(int i=l-1;i>=0;--i)
		h=h*p+a[i];
	int now=0;
	while(now<L)
	{
		if(h==ha)
		{
			cout<<c;
			h=0;
			now+=l;
			for(int i=l+now-1;i>=now;--i)
				h=h*p+a[i];
		}
		else
		{
			printf("%c",a[now]);
			h-=a[now]*ksm(l-1);
			++now;
			h*=p;
			h+=a[now+l-1];
		}
	}
	return 0;
}
