#include<bits/stdc++.h>
using namespace std;
int a[5000005],b[5000005],c[10000005];
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
int main()
{
	int n,m,k;
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	int p1=1,p2=1,now=0;
	while(p1<=n&&p2<=m)
	{
		if(a[p1]<b[p2])c[++now]=a[p1++];
		else c[++now]=b[p2++];
	}
	while(p1<=n)c[++now]=a[p1++];
	while(p2<=m)c[++now]=b[p2++];
	printf("%d\n",c[k]);
	return 0;
}
