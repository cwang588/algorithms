#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t%2)	
			++num; 
	}
	printf("%d\n",min(n-num,num));
	return 0;
}
