#include<bits/stdc++.h>
using namespace std;
int a[400005],num[35];
long long numm[35];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<=28;++i)
		for(int j=1;j<=n;++j)
			if(a[j]&(1<<i))
				++num[i];
	int ans=0;
	for(int i=0;i<=26;++i)
	{
		numm[i]+=(long long)num[i]*(long long)(n-num[i]);
		if(numm[i]%2)ans+=(1<<i);
		int num1=0,num2=0;
		for(int j=1;j<=n;++j)
		{
			if(a[j]&(1<<i))
			{
				if(a[j]&(1<<(i+1)))++num1;
				else ++num2;
			}
		}
		numm[i+1]+=((long long)num1*(long long)(num1-1))/2+((long long)num2*(long long)(num2-1))/2;
		numm[i+1]-=(long long)num1*(long long)num2;
	}
	printf("%d\n",ans);
	return 0;
}
