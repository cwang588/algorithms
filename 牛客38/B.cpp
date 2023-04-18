#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n,m,x,y,t;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&t);	
	int q=x*m*(n-1)*(m-1)+(n-1)*(m-1)*y*n,p=x*m*(x-1)*(m-1)+y*n*(y-1)*(n-1);
	if(!t)
		printf("%.3f",(double)p/(double)q);
	else
		printf("%d/%d",p/gcd(q,p),q/(gcd(q,p)));
	return 0;
} 
