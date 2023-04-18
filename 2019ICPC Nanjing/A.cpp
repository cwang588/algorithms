#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans=n/2;
		if(n%2)++ans;
		++ans;
		printf("%d\n",ans);
	}
	return 0;
}
