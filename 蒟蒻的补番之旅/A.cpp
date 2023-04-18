#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
struct dian
{
	int num,id;
}a[1005];
int tong[1005];
bool cmp(dian x,dian y)
{
	return x.num<y.num;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i].num);
	sort(a+1,a+1+n,cmp);
	int now=1,cnt=0;
	while(now<=n)
	{
		if(a[now].num>a[now-1].num)
		{
			++cnt;
			m[cnt]=a[now].num;
		}
		a[now].id=cnt;
		++now;
		++tong[cnt];
	}
	int Max=0;
	for(int i=1;i<=1000;++i)
		Max=max(Max,tong[i]);
	if(Max>cnt)
	{
		printf("%d 1\n",cnt);
		for(int i=1;i<=cnt;++i)
		{
			printf("%d ",tong[i]);
			for(int j=1;j<=tong[i];++j)
				printf("%d ",m[i]);
			printf("\n");
		}
	}
	else
	{
		int now=cnt;
		printf("%d 2\n",Max);
		for(int j=1;j<=Max;++j)
		{
			printf("%d ",now);
			for(int i=1;i<=cnt;++i)
			{
				if(!tong[i])
					continue;
				--tong[i];
				if(!tong[i])
					--now;
				printf("%d ",m[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
