#include<bits/stdc++.h>
using namespace std;
char a[105];
int n;
long long mi(int x)
{
	long long re=1;
	for(int i=1;i<=x;++i)re*=2;
	return re;
}
long long calc(int start)
{
	long long re=0;
	for(int i=start;i<=n;++i)
	{
		re*=2;
		if(a[i]=='1')++re;
	}
	return re;
}
int main()
{
	long long k;
	cin>>k;
	cin>>(a+1);
	int ans=0;
	n=strlen(a+1);
	long long now=0;
	for(int i=1;i<=n;++i)
	{
		now*=2;
		if(a[i]=='1')now++;
	}
	int p=1;
	int s=1;
	while(now>k)
	{
		if(a[p]=='1'&&a[p+1]=='1')
		{
			++ans;
			now-=mi(n-p);
			++p;
			++s;
		}
		else
		{
			for(int i=p+1;i<=n;++i)
			{
				if(a[i]=='1')
				{
					for(int j=i;j>s;--j)a[j]=a[j-1];
					++s;
					++ans;
					now=calc(s);
					if(now<=k)return !printf("%d",ans);
				}
			}
			while(now>k)
			{
				now>>=1;
				++ans;
			}
			return !printf("%d",ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
