#include<cstdio>
#include<iostream>
using namespace std;
char a[105];
int ans[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int tot=0,now=1;
	while(now<=n)
	{
		while(a[now]!='B'&&now<=n)
			++now;
		if(now>n)
			break;
		++tot;
		int sum=0;
		while(a[now]=='B')
		{
			++sum;
			++now;
		}
		ans[tot]=sum;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)	
		cout<<ans[i]<<' ';
	return 0;
}
