#include<cstdio>
#include<iostream> 
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long long n,a,b;
		cin>>n>>a>>b;
		if(n%2)
		{
			if(a*2<=b)
				cout<<a*n<<endl;
			else
				cout<<n/2*b+a<<endl;
		}
		else
		{
			if(a*2<=b)
				cout<<a*n<<endl;
			else
				cout<<n/2*b<<endl;
		}
	}
	
	return 0;
} 
