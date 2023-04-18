#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int main()
{
	int n;
	while(cin>>n)
	{
		memset(a,' ',sizeof(a));
		int now=0;
		for(int i=1;i<=2*n+1;++i)
		{
			if(i%2)
			{
				for(int j=1;j<=2*n+1;++j)
				{
					now%=26;
					a[i][j]='a'+now;
					++now;
				}
			}
			else
			{
				for(int j=2*n+1;j>=1;--j)
				{
					now%=26;
					a[i][j]='a'+now;
					++now;
				}				
			}
		}
		for(int i=1;i<=2*n+1;++i)
		{
			for(int j=1;j<=2*n+1;++j)
				cout<<a[i][j];
			cout<<endl;
		}
	}
	
	return 0;
}
