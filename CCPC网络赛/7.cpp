#include<bits/stdc++.h>
using namespace std;
char a[15][1050][1050];
void init()
{
	a[1][1][1]='C';
	for(int i=2;i<=11;++i)
	{
		for(int j=1;j<=pow(2,i-2);++j)
		{
			for(int k=1;k<=pow(2,i-2);++k)
			{
				if(a[i-1][j][k]=='C')
				{
					a[i][2*j-1][2*k-1]='C';
					a[i][2*j-1][2*k]='C';
					a[i][2*j][2*k-1]='P';
					a[i][2*j][2*k]='C';					
				}
				else
				{
					a[i][2*j-1][2*k-1]='P';
					a[i][2*j-1][2*k]='P';
					a[i][2*j][2*k-1]='C';
					a[i][2*j][2*k]='P';						
				}
			}
		}
	}
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		++n;
		for(int i=1;i<=pow(2,n-1);++i)
		{
			for(int j=1;j<=pow(2,n-1);++j)
				cout<<a[n][i][j];
			cout<<endl;
		}
	}
	return 0;
}
