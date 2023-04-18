#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int w[10005];
int ans[10005]={0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
long long mi(long long t)
{
	if(!t)
		return 1;
	if(t==1)
		return 2;
	if(t%2)
		return mi(t/2)*mi(t/2)*2;
	else
		return mi(t/2)*mi(t/2);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(w,0,sizeof(w));
		long long n,x;
		bool zero=false;
		scanf("%d",&n);
		if(n==1)
		{
			cout<<'0'<<endl;
			continue;
		}
		for(int i=0;i<=30;++i)
		{
			if((1<<i)&n)
			{
				w[i]=1;
				x=i;
			}
		}
		for(int i=0;i<=x;++i)
			if(!w[i])
				zero=true;
		if(!zero)
			printf("%d\n",ans[x]);
		else
			cout<<mi(x+1)-1<<endl;
	}
	return 0;
}
