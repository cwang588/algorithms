#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		cin>>n;
		long long tot1=0,tot2=0;
		long long t;
		for(long long i=1;i<=n;++i)
		{
			cin>>t;
			tot1+=t;
			tot2+=t*t;
		}
		cout<<tot2*n-tot1*tot1<<endl; 
	}
	return 0;
}
