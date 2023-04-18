#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int q;
		cin>>q;
		while(q--)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);		
			if(b-a==d-c)printf("draw\n");
			else if(b-a>d-c)printf("cslnb\n");
			else printf("sjfnb\n");
		}
	}
	return 0;
}
