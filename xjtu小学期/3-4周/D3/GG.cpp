#include<bits/stdc++.h>
using namespace std;
int a[55],t[25],tt[25];
void print(int x)
{
	memset(tt,0,sizeof(tt));
	int num=0;
	while(x)
	{
		tt[++num]=x&1;
		x>>=1;
	}
	for(int i=5;i>=1;--i)
		printf("%d",tt[i]);
	printf(" ");
	return;
}
void solve(int l,int r)
{
	if(l==r)
		return;
	for(int i=0;2*i+l<=r;++i)
		t[i+1]=a[l+2*i];
	for(int i=0;2*i+l+1<=r;++i)
		t[(r-l+2)/2+1+i]=a[l+2*i+1];
	for(int i=l;i<=r;++i)
		a[i]=t[i-l+1];
	solve(l,(l+r)>>1);
	solve(((l+r)>>1)+1,r);
}
int main()
{
	for(int i=1;i<=16;++i)
	{
		for(int j=1;j<=i;++j)
			a[j]=j;
		solve(1,i);	
		for(int j=1;j<=i;++j)
			printf("%5d ",a[j]);
		printf("\n");
//		for(int j=1;j<=i;++j)
//			print(a[j]);
		cout<<endl;
	}
	return 0;
}
