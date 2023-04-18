#include<bits/stdc++.h>
using namespace std;
int n;
int Min=2147483647,num=0;
char ans[100005];
void dfs(int now)
{
	if(now==n)
	{
		int tmp=0;
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
				if(judge(i,j))
					++tmp;	
	}
}
int main()
{
	scanf("%d",&n);
	dfs(0);
	printf("%lld",num);
	return 0;
} 
