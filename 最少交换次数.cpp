#include<cstdio>
#include<iostream>
using namespace std;
int n;
int sum[1000500];
int shu[1000005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int num)
{
	while(x<=n)
	{
		shu[x]+=num;
		x+=lowbit(x);		
	}
}
int he(int x)
{
	int re=0;
	while(x>0)
	{
		re+=shu[x];
		x-=lowbit(x);		
	}
}
int main()
{
	int tot=0;
	int t;
//	while(cin>>t) 
//		sum[++n]=t;
	cin>>n;
	for(int i=1;i<=n;++i)
	{	
		cin>>t;
		tot+=n-he(t-1);
		add(t,1);
	}
	printf("%d",tot);
	return 0;
} 
