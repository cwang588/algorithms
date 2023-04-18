#include<cstdio>
#include<iostream> 
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		long long ans=(long long)(a-b)*(k/2);
		if(k%2)
			ans+=a;
		cout<<ans<<endl;
	}
	
	return 0;
}
