#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	int num1=0,num2=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==b[i])continue;
		if(a[i])++num1;
		else ++num2;
	}
	if(!num1)return !printf("-1\n");
	if(num1>num2)return !printf("1\n");
	if(num1==num2)return !printf("2\n");
	printf("%d\n",num2/num1+1);
	return 0;
}
