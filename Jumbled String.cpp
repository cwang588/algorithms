#include <bits/stdc++.h>
using namespace std;
int main()
{   
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==0&&b==0&&c==0&&d==0)
	{ 
		printf("0\n");
		return 0;
	}    
	long long x,y;
	x=(1+sqrt((double)(1+8*a)))/2;
	if(x*(x-1)/2!= a)
	{
		printf("impossible\n");
		return 0;
	}    
	y=(1+sqrt((double)(1+8*d)))/2;
	if(y*(y-1)/2!=d)
	{
	    printf("impossible\n");
		return 0;
	} 
	if(a==0&&d==0)
	{ 
		if(b==1&&c==0)
		{
		    printf("0");
			printf("1\n");
		}
		else if(c==1&&b==0)
		{
		    printf("1");
			printf("0\n");
		}
		else 
			printf("impossible\n");
        return 0;
    }
    if(b==0&&c==0)
    {
	    if(a==0)
		{
            for(long long i=1;i<=y;i++)
				printf("1");
            printf("\n");
        }
		else if(d==0)
        {
		    for(long long i=1;i<=x;i++)
				printf("0");
            printf("\n");
        }
        else 
			printf("impossible\n");
        return 0;
    }
	if(x*y!=b+c)
	{
	    printf("impossible\n");
        return 0;
    }
	long long q,w; 
	q=b/y; 
	w=b%y;
	for(long long i=1;i<=q;i++)
		printf("0");
	for(long long i=1;i<=y-w;i++)
		printf("1");
	if(q!=x)
	    printf("0"); 
    for(long long i=1;i<=w;i++) 
		printf("1");
    for(long long i=1;i<=x-q-1;i++)
		printf("0"); 
	return 0;
}

