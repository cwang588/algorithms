#include<cstdio>
#include<cstring>
using namespace std;
int a[11]={0,2,3,4,5,6,7,8,9,10,19260817};
int sx[11];
bool usd[11];
int num;
bool check(int x)
{
	memset(usd,false,sizeof(usd));
	for(int i=1;i<=x;++i)
	{
		int t=sx[i];
		while(usd[t])
		{
			if(a[t]<=x&&t!=a[t])
				t=a[t];
			else
				return false; 
		}
		usd[t]=true;
	}
	return true;
}
void dfs(int re,int x)
{
	if(!re)
	{
		if(check(x))
			++num;
		return;
	}
	for(int i=1;i<=x;++i)
	{
		sx[x-re+1]=i;
		dfs(re-1,x);
	}
}
int ans(int x)
{
	num=0;
	for(int i=1;i<=x;++i)
	{
		sx[1]=i;
		dfs(x-1,x);
	}
	return num;
}
int main()
{
	for(int i=1;i<=10;++i)
		printf("%d\n",ans(i));
	return 0;
}
