#include <iostream>
using namespace std;
int main()
{
	int n,x,tot=0;	
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		if(!x)
		{
			int j=i;
			while(j)
			{
				tot+=(j%10?0:1);
				j/=10;
			}
		}
		else
		{
			int j=i;
			while(j)
			{
				tot+=(j%10==x?1:0);
				j/=10;
			}
		}
	}
	cout<<tot;
	return 0;
}
