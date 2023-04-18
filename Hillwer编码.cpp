#include<cstring>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int sum[100005];
char line[605];
void cheng(int x)
{
	for(int i=1;i<=sum[0];++i)
		sum[i]*=x;
	for(int j=1;j<=sum[0]+3;++j)
	{
		sum[j+1]+=sum[j]/10;
		sum[j]%=10;
	}
	for(int j=sum[0]+3;j>=1;--j)
		if(sum[j])
		{
			sum[0]=j;
			break;
		}
}
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	r%=26;
	for(int i=1;i<=n;++i)
	{
		memset(line,' ',sizeof(line));
		memset(sum,0,sizeof(sum));
		sum[0]=sum[1]=1;
		scanf("%s",line);
		int l=strlen(line);
		for(int j=0;j<l;++j)
		{
			line[j]+=r;
			if(line[j]>'Z')
				line[j]-=26;
		}
		printf("%s\n",line);
		for(int j=0;j<l;++j)
			cheng((int)line[j]);
		for(int j=sum[0];j>=1;--j)
			printf("%d",sum[j]);
		printf("\n");
	}
	return 0;
}
