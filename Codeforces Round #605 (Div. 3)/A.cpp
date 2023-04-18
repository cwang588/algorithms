#include<bits/stdc++.h>
using namespace std;
int x[15];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		cin>>x[1]>>x[2]>>x[3];
		sort(x+1,x+4);
		if(x[3]-x[1]<=2)printf("0\n");
		else printf("%d\n",(x[3]-x[1]-2)*2);
	}
	return 0;
}
