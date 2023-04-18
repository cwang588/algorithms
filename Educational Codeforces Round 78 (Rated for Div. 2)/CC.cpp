#include<bits/stdc++.h>
using namespace std;
int suml[200005],sumr[200005],l[200005],r[200005];
int fir[1000005];
int nmsl()
{
	return 0;
}
int two()
{
	return nmsl();
}
int one()
{
	return two();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n*5;i++) fir[i]=1000000007;
		for(int i=1;i<=n;i++) scanf("%d",&l[i]);
		for(int i=n;i;i--) suml[i]=suml[i+1]+(l[i]==1?1:-1);
		for(int i=1;i<=n;i++) scanf("%d",&r[i]);
		fir[2*n]=0;
		for(int i=1;i<=n;i++)
		{
			sumr[i]=sumr[i-1]+(r[i]==1?1:-1);
			if(sumr[i]!=0&&fir[sumr[i]+n*2]==1000000007) fir[sumr[i]+n*2]=i;
		}
		int sum=suml[1]+sumr[n];
		int ans=fir[sum+n*2];
		for(int i=n;i;i--)
		{
			int tmp=n-i+1+fir[sum-suml[i]+n*2];
			if(tmp<ans) ans=tmp;
		}
		printf("%d\n",ans);
		for(int i=0;i<=n;i++) suml[i]=sumr[i]=0;
		for(int i=0;i<=n*5;i++) fir[i]=1000000007;
	}
	return one();
}

