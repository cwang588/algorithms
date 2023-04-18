#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[2005],b[2005];
int ans;
long long fun(long long x)
{
	int ans=1;
	for(int i=2;i<=x;i++)
	{
		int cnt=0;
		while(x%i==0)
		{
			cnt++;
			x/=i;
		}
		ans*=(cnt+1);
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=fun(a[i]);
	}
	for(int i=1;i<=n;++i)	
		for(int j=i+1;j<=n;++j)
		{
			if(fun(a[i]*a[j])<=10)
				++ans;
		}
	printf("%d",ans);
	return 0;
}
