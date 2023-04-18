#include<bits/stdc++.h>
using namespace std;
priority_queue<int,int>;
struct boy
{
	bool ky[65];
	long long b;
}bnd[7005];
int num[65];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		long long a;
		cin>>a;
		for(int j=0;j<60;++i)
		{
			if((1<<j)&a)
			{
				bnd[i].ky[j]=true;
				++num[j];
			}
		}
	}
	return 0;
}
