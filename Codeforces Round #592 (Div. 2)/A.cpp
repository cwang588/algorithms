#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=a/c,y=b/d;
		if(a%c)++x;
		if(b%d)++y;
		if(x+y>k)printf("-1\n");
		else printf("%d %d\n",x,y);
	}
	
	return 0;
}
