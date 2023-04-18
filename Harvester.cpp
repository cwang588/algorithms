#include<bits/stdc++.h>
using namespace std;
long long *a[100005],c[100005],hang[100005],lie[100005];
int n,m,tep;
long long gethang()
{
	long long Max1=0,Max2=0,Max3=0,Max4=0;
	for(int i=1;i<=n;++i)
	{
		if(hang[i]>=Max1)
		{
			Max4=Max3;
			Max3=Max2;
			Max2=Max1;
			Max1=hang[i];
		}
		else if(hang[i]>=Max2)
		{
			Max4=Max3;
			Max3=Max2;
			Max2=hang[i];
		}
		else if(hang[i]>=Max3)
		{
			Max4=Max3;
			Max3=hang[i];
		}
		else if(hang[i]>=Max4)Max4=hang[i];
	}
	return Max1+Max2+Max3+Max4;
}
long long getlie()
{
	long long Max1=0,Max2=0,Max3=0,Max4=0;
	for(int i=1;i<=n;++i)
	{
		if(lie[i]>=Max1)
		{
			Max4=Max3;
			Max3=Max2;
			Max2=Max1;
			Max1=lie[i];
		}
		else if(lie[i]>=Max2)
		{
			Max4=Max3;
			Max3=Max2;
			Max2=lie[i];
		}
		else if(lie[i]>=Max3)
		{
			Max4=Max3;
			Max3=lie[i];
		}
		else if(lie[i]>=Max4)Max4=lie[i];
	}
	return Max1+Max2+Max3+Max4;
}
int main()
{
	scanf("%d%d",&n,&m);
	int now=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%I64d",&c[++now]);
	if(n<=m)
	{
		for(int i=1;i<=n;i++)
			a[i]=(long long *)malloc(sizeof(long long)*(m+5));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[i][j]=c[(i-1)*m+j];
	}
	else
	{
		swap(n,m);
		for(int i=1;i<=n;i++)
			a[i]=(long long *)malloc(sizeof(long long)*(m+5));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[i][j]=c[(j-1)*n+i];
	}
	tep=n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			hang[i]+=a[i][j];
			lie[j]+=a[i][j];
		}
	long long ans=0;
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
		{
			long long now=hang[i]+hang[j];
			long long Max1=0,Max2=0;
			for(int k=1;k<=m;++k)
			{
				long long noww=lie[k]-a[i][k]-a[j][k];
				if(noww>=Max1)
				{
					Max2=Max1;
					Max1=noww;
				}
				else if(noww>Max2)Max2=noww;
			}
			ans=max(ans,now+Max1+Max2);
		}
	ans=max(ans,gethang());
	ans=max(ans,getlie());
	if(n==1)printf("%I64d",hang[1]);
	else printf("%I64d\n",ans);
	for(int i=1;i<=tep;i++)free(a[i]);	
	return 0;
}
