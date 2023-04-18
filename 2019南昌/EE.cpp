#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int now=0;
	printf("%d ",now);
	for(int i=2;i<=n;++i)
	{	
		now=(now+m)%i;
		printf("%d ",now);
	}
	return 0;
} 
