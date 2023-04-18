#include<iostream>
#include<cstdio>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int num(int x)
{
	if(!x)
		return 6;
	int cnt=0;
	while(x)
	{
		cnt+=a[x%10];
		x/=10;
	}
	return cnt;
}
int main()
{
   	int n,k,tot=0;
   	scanf("%d%d",&n,&k);
   	int sum=n/k-4-num(n);
   	for(int i=0;i<=n/2;++i)
   	{
   		int sum1,sum2;
   		sum1=num(i);
   		sum2=num(n-i);
   		if(sum1+sum2==sum)
   			++tot;
   	}
   	printf("%d",tot);
    return 0;
}
