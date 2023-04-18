#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,n;
		cin>>a>>b;
		n=abs(a-b);
		if(!n)printf("0\n");
		else if(n%2)
		{
			for(long long i=1;;++i)
			{
				if(i*(i+1)/2%2==0)continue;
				if(i*(i+1)/2>=n)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else
		{
			for(long long i=1;;++i)
			{
				if(i*(i+1)/2%2)continue;
				if(i*(i+1)/2>=n)
				{
					cout<<i<<endl;
					break;
				}
			}			
		}
	}
	
	return 0;
}
