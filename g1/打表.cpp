#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	return b?gcd(b,a%b):a;
}
int main()
{
	int i;
	scanf("%d",&i);
	int m=0;
	for(int j=1;j<i;++j)
		m=max(m,gcd(j^i,i&j));
	printf("%d\n",m); 
	return 0;
}
