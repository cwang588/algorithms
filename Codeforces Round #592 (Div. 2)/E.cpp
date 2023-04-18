#include<bits/stdc++.h>
using namespace std;
long long sum[100005];
long long index[100005];
long long num[100005];
int main()
{
	int n;
	long long k;
	cin>>n>>k;	
	for(int i=1;i<=n;++i)cin>>sum[i];
	sort(sum+1,sum+1+n);
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(sum[i]!=sum[i-1])index[++cnt]=sum[i];
		++num[cnt];
	}
	int l=1,r=cnt;
	while(l<r)
	{
		if(num[l]<num[r])
		{
			if(num[l]*(index[l+1]-index[l])<=k)
			{
				++l;
				k-=num[l]*(index[l]-index[l-1]);
				num[l]+=num[l-1];
			}
			else
			{
				return !printf("%d\n",index[r]-(index[l]+k/num[l]));
			}
		}
		else
		{
			if(num[r]*(index[r]-index[r-1])<=k)
			{
				k-=num[r]*(index[r]-index[r-1]);
				num[r-1]+=num[r];
				--r;
			}
			else
			{
				return !printf("%d\n",index[r]-index[l]-k/num[r]);
			}
		}
	}
	printf("0\n");
	return 0;
}
