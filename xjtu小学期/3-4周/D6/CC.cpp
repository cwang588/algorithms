#include<bits/stdc++.h>
using namespace std;
int a[105],l[105],r[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i],&l[i],&r[i]);
	for(int i=1;i<=n;++i)
	{
		int ans=0;
		for(int j=1;j<=20;++j)
		{
			int num1=0,num2=0;
			for(int k=1;k<i;++k)
				if(a[k]==j)
					++num1;
			for(int k=i+1;k<=n;++k)
				if(a[k]==j)
					++num2;
			ans+=num1*num2;			
		}
		printf("%d\n")
	}
	return 0;
}
