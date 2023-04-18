#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>m;
int a[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		m.clear();
		int n;
		scanf("%d",&n);
		int num1=0,num2=0;
		for(int i=1;i<=2*n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)++num1;
			else ++num2;
		}
		if(num1==num2)
		{
			printf("0\n");
			continue;
		}
		int nr1=0,nr2=0;
		for(int i=n+1;i<=2*n;++i)
		{
			if(a[i]==1)++nr1;
			else ++nr2;
			int tt=nr1-nr2;
			if(!m[tt])
				m[tt]=i;
		}
		int nl1=0,nl2=0;
		int ans=2147483647;
		for(int i=n;i>=1;--i)
		{
			if(a[i]==1)++nl1;
			else ++nl2;
			int tt=(num1-num2)-(nl1-nl2);
			if(m[tt])ans=min(ans,m[tt]-i+1);			
		}
		printf("%d\n",ans);
	}
	return 0;
}
