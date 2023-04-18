#include<bits/stdc++.h>
using namespace std;
int a[5005],tmp[5005],n;
bool usd[5005];
bool judge(int index)
{
	int num1=0,num2=0;
	int now=0,numnow=0,tot=0;
	for(int i=1;i<=n;++i)
	{
		if(i==index)
		{
			if(numnow>0)
			{
				if(now==1)
				{
					tmp[++tot]=numnow;
					usd[tot]=true;
				}
				else
				{
					tmp[++tot]=numnow;
					usd[tot]=false;
				}
			}
			numnow=now=0;
			continue;
		}
		if(a[i]>a[index])
		{
			++num1;
			if(now==1)++numnow;
			else if(now==0)numnow=now=1;
			else 
			{
				tmp[++tot]=numnow;
				numnow=1;
				now=1;
				usd[tot]=false;
			}
		}
		else
		{
			++num2;
			if(now==-1)++numnow;
			else if(now==0)
			{
				numnow=1;
				now=-1;
			}
			else 
			{
				tmp[++tot]=numnow;
				numnow=1;
				now=-1;
				usd[tot]=true;
			}
		}
	}
	if(numnow>0)
	{
		if(now==1)
		{
			usd[++tot]=true;
			tmp[tot]=numnow;
		}
		else
		{
			usd[++tot]=false;
			tmp[tot]=numnow;
		}
	}
	int tot1=0,tot2=0;
	for(int i=1;i<=tot;++i)
	{
		if(usd[i])
		{
			if(tmp[i]>=3)
			{
				if(tmp[i]%2)tot1+=tmp[i]/2*2;		
				else tot1+=(tmp[i]-2)/2*2;
			}
		}
		else 
		{
			if(tmp[i]>=3)
			{
				if(tmp[i]%2)tot2+=tmp[i]/2*2;		
				else tot2+=(tmp[i]-2)/2*2;
			}
		}
	} 
	if(num1==num2)return true;
	if(num1>num2)return tot1>=num1-num2;
	else return tot2>=num2-num1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
		{
			if(judge(i))printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
