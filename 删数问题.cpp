#include<bits/stdc++.h>
using namespace std;
char a[10005];
bool usd[10005];
int main()
{
	ios::sync_with_stdio(false);
	cin>>(a+1);
	int n=strlen(a+1),k;
	cin>>k;
	for(int i=1;i<n;++i)
		if(a[i]>a[i+1])
		{
			usd[i]=true;
			--k;
			if(!k)break;
			for(int j=i-1;j>=1;--j)
			{
				if(!usd[j]&&a[j]>a[i+1])
				{
					usd[j]=true;
					--k;
					if(!k)break;
				}
				else if(usd[j])continue;
				else break;
			}
			if(!k)break;
		}
	if(k>0)
	{
		for(int i=n;i>=1;--i)
			if(!usd[i]&&k>0)
			{
				usd[i]=true;
				--k;
				if(!k)break;
			}
	}
	bool remain=false,zero=true;
	for(int i=1;i<=n;++i)
	{
		if(!usd[i])
		{
			if(a[i]!='0')zero=false;
			remain=true;
			if(!zero)printf("%c",a[i]);
		}
	}
	if(!remain||zero)printf("0");
	printf("\n");
	return 0;
}
