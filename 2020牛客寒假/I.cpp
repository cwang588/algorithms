#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(100*a[9]>=80*m)return !printf("Yes\n");
	int num=0;
	for(int i=1;i<=n;++i)if(a[i]>a[9])++num;
	printf("%s\n",num<=2?"Yes":"No");
	return 0;
}
