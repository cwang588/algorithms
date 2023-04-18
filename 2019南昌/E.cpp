#include<bits/stdc++.h>
using namespace std;
int a[400000005];
void work(int n,int m)
{
	int tail=n,head=0;
	while(head<tail)
	{
		++head;
	//	printf("%d ",a[head]);
		for(int i=1;i<=m;++i)
			a[tail+i]=a[head+i];
		head+=m;
		tail+=m;
	}
}
int main()
{
//	for(int now=1;now<=50;++now)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=4000000;++i)a[i]=i;
		work(4000000,10);
		printf("\n");
	}	
	
	return 0;
}
