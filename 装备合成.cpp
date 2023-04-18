#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,ans;
		scanf("%d%d",&x,&y);
		if(x>=4*y)ans=y;
		else if(x*3<=2*y)ans=x/2;
		else ans=(x+y)/5;
		printf("%d\n",ans);
	}
	
	return 0;
}
