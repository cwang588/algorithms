#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char t[105];
int a[105],b[105];
bool pd()
{
	for(int i=1;i<=a[0]/2;++i)
		if(a[i]!=a[a[0]-i+1])
			return false;
	return true;
}
int main()
{
	int n,l;
	scanf("%d",&n);
	cin>>t;
	l=a[0]=b[0]=strlen(t);
	for(int i=0;i<l;++i)
	{
		if(t[i]>='0'&&t[i]<='9')
			a[l-i]=b[i+1]=t[i]-'0';
		else
			a[l-i]=b[i+1]=t[i]-'A'+10;
	}
	for(int i=1;i<=30;++i)
	{
		for(int j=1;j<=a[0];++j)
			a[j]+=b[j];
		for(int j=1;j<=a[0];++j)
			if(a[j]>=n)
			{
				a[j]-=n;
				++a[j+1];
			}
		if(a[a[0]+1])
			++a[0];
		if(pd())
			return !printf("STEP=%d",i);
		for(int j=1;j<=a[0];++j)
			b[a[0]-j+1]=a[j];
		b[0]=a[0];
	}
	printf("Impossible!");
	return 0;
}
