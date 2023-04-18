#include<bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	cin>>(a+1);
	for(int i=1;i<=n;++i)
	{
		int num=i%k;
		if(!num)num=k;
		b[i]=a[num];
	}
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>b[i])
		{
			now=1;
			break;
		}
		else if(a[i]<b[i])
		{
			now=2;
			break;
		}
		else;
	}
	printf("%d\n",n);
	if(now==0||now==2)
	{
		for(int i=1;i<=n;++i)cout<<b[i];
		return !printf("\n");
	}
	++b[k];
	for(int i=k;i>=1;--i)
	{
		if(b[k]>'9')b[i]-=10,++b[i-1];
		else break;
	}
	for(int i=k+1;i<=n;++i)
	{
		int num=i%k;
		if(!num)num=k;
		b[i]=b[num];
	}
	for(int i=1;i<=n;++i)cout<<b[i];
	cout<<endl;
	return 0;
}
