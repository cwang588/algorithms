#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct human
{
	char name[15];
	int k,num;
}h[105];
bool usd[10000005];
bool cmp(human a,human b)
{
	if(a.num!=b.num)
		return a.num>b.num;
	return a.k<b.k;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		memset(usd,false,sizeof(usd));
		int ans=0;
		cin>>h[i].name>>h[i].k;
		for(int j=1;j<=h[i].k;++j)
		{
			int t;
			scanf("%d",&t);
			if(!usd[t])
			{
				++ans;
				usd[t]=true;
			}
		}
		h[i].num=ans;
	}
	sort(h+1,h+1+n,cmp);
	if(n<3)
	{
		for(int i=1;i<=n;++i)
			printf("%s ",h[i].name);
		for(int i=n+1;i<3;++i)
			printf("- ");
		printf("-");
	}
	else
	{
		for(int i=1;i<=3;++i)
		{
			if(i<3)
				printf("%s ",h[i].name);
			else
				printf("%s",h[i].name);
		} 
	}
	return 0;
}
