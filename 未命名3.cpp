#include<cstdio>

int T,l,r,ans; 
int split(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++)
			ans+=split(i);
		printf("%d\n",ans);
	}
}

