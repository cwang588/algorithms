#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double a;
		cin>>s>>a;
		if(s=="1")
		{
			printf("%.10lf\n",1.666666666666667*a);
			continue;
		}
		else if(s=="2")
		{
			printf("%.10lf\n",1.615384615384615*a);
			continue;
		}
		else if(s=="3")
		{
			printf("%.10lf\n",1.618181818181818*a);
			continue;
		}
		else if(s=="4")
		{
			printf("%.10lf\n",1.618025751072961*a);
			continue;
		}
		else if(s=="5")
		{
			printf("%.10lf\n",1.618034447821682*a);
			continue;
		}
		else if(	s=="6")
		{
			printf("%.10lf\n",1.618033963166706*a);
			continue;
		}
		else if(s=="7")
		{
			printf("%.10lf\n",1.618033990175597*a);
			continue;
		}	
		else if(s=="8")
		{
			printf("%.10lf\n",1.618033988670443*a);
			continue;
		}
		else if(s=="9")
		{
			printf("%.10lf\n",1.618033988754322*a);
			continue;
		}					
		else if(s=="10")
		{
			printf("%.10lf\n",1.618033988749648*a);
		}
		else if(s=="11")
		{
			printf("%.10lf\n",1.618033988749909*a);
		}
		else if(s=="12")
		{
			printf("%.10lf\n",1.618033988749894*a);
		}
		else if(s=="13")
		{
			printf("%.10lf\n",1.618033988749895*a);
		}
		else
		{
			printf("%.10lf\n",1.618033988749895*a);
		}
	}
	return 0;
}
