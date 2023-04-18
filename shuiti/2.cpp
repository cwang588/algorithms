#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		long long t;
		cin>>t;
		long long tot=0;
		while(t)
		{
			tot+=t%10;
			t/=10;
		}
		if(tot%6==0)
			++sum;
	}
	cout<<sum;
	return 0;
}
