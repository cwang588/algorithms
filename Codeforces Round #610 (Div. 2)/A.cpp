#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,r;
		scanf("%d%d%d%d",&a,&b,&c,&r);
		if(a>b)swap(a,b);
		int L=c-r,R=c+r;
		if(R<=a||L>=b)printf("%d\n",b-a);
		else if(R>=b&&a>=L)printf("0\n");
		else if(R<=b&&a<=L)printf("%d\n",b-R+L-a);
		else if(R<=b)printf("%d\n",b-R);
		else printf("%d\n",L-a);
	} 
	return 0;
}
