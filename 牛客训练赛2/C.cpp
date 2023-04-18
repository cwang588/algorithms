#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
char num[1005];
int a[100005];
int b[100005]={1,1};
void cheng()
{
	for(int i=1;i<=b[0];++i)
		b[i]*=3;
	for(int i=1;i<=b[0];++i)
	{
		b[i+1]+=b[i]/10;
		b[i]%=10;
	}
	if(b[b[0]+1])
		++b[0];
	return;
}
bool cmp()
{
	if(a[0]<b[0])
		return true;
	if(a[0]>b[0])
		return false;
	for(int i=b[0];i>=1;--i)
	{	
		if(b[i]>a[i])
			return true;
		if(a[i]>b[i])
			return false;
	}
	return true;
}
int main()
{
	cin>>num;
	a[0]=strlen(num);
	for(int i=1;i<=a[0];++i)
		a[i]=num[a[0]-i]-'0';
	for(int i=1;i<=a[0];++i)
		a[i]*=2;
	++a[1];
	for(int i=1;i<=a[0];++i)
		if(a[i]>10)
		{
			++a[i+1];
			a[i]-=10;
		}
	if(a[a[0]+1])
		++a[0];
	int m;
	for(m=1;;++m)
	{
		cheng();
		if(cmp())
			break;
	}
	printf("%d",m);
	return 0;
}
