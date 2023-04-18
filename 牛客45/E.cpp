#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	bool xswin;
	if(n%2==1)
		xswin=false;
	else
		xswin=true;
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		bool jh=false;
		if(b==1)
		{
			xswin=!xswin;
			jh=true;
		}
		if(xswin)
			printf("Alice\n");
		else
			printf("Bob\n");
		if(jh)
			xswin=!xswin;
	}
	return 0;
}
