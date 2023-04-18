#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	int ans=0;
	while(n>2)
	{
		long long tmp=0;
		for(long long i=1;i*i<=n;++i)
		{
			if(n%i==0)tmp+=2;
			if(i*i==n)--tmp;
		}
		n=tmp;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}
