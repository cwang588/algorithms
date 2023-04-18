#include<bits/stdc++.h>
using namespace std;
int a[400005],now[400005],t[400005];
long long num[45];
int n;
int Find(int x)
{
	int l=1,r=n+1;
	while(l<r-1)
	{
		int m=(l+r)>>1;
		if(t[m]>=x)r=m;
		else l=m;
	}
	if(t[l]>=x)return l;
	return r;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0;
	for(int i=0;i<=26;++i)
	{
		int numm=0;
		for(int j=1;j<=n;++j)
		{
			if(a[j]&(1<<i))
			{
				++numm;
				t[j]=now[j]+(1<<i);
			}
			else t[j]=now[j];
		}
		long long tot=(long long)numm*(long long)(n-numm);	
		if((tot+num[i])%2)ans+=(1<<i);
		sort(t+1,t+1+n);
		int tmp=(1<<(i+1));
		long long totnum=0;
		for(int j=1;j<=n;++j)
		{
			int noww=Find(tmp-t[j]);
			if(noww==n+1)continue;
			totnum+=(n-noww);
			if(j<noww)++totnum;
		}	
		totnum/=2;
		for(int j=1;j<=n;++j)
		{
			if(a[j]&(1<<i))
				now[j]+=(1<<i);
		}
		num[i+1]+=totnum;
	}
	printf("%d\n",ans);
	return 0;
}
