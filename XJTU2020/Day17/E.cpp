#include<bits/stdc++.h>
using namespace std;
int fac[10005];
void init()
{
	fac[0]=1;
	for(int i=1;i<=10;++i)fac[i]=fac[i-1]*i;
}
int a[1005],tmp[1005];
struct number
{
	int num[15];
}N[10000005];
int n;
bool cmp(number x,number y)
{
	for(int i=1;i<n;++i)if(x.num[i]!=y.num[i])return x.num[i]<y.num[i];
}
int main()
{
//	freopen("data.txt","w",stdout);
	init();
//	printf("int ans[15][10005][15]={\n");
	for(int i=2;i<=9;++i)
	{
		n=i;
		int now=0;
		for(int j=1;j<=i;++j)a[j]=j;
		for(int j=1;j<i;++j)tmp[j]=a[j+1]-a[j];
		++now;
		memset(N[now].num,0,sizeof(N[now].num));
		for(int j=1;j<i;++j)N[now].num[j]=tmp[j];
		while(next_permutation(a+1,a+1+i))
		{
			for(int j=1;j<i;++j)tmp[j]=a[j+1]-a[j];
			++now;
			memset(N[now].num,0,sizeof(N[now].num));
			for(int j=1;j<i;++j)N[now].num[j]=tmp[j];
		}
		sort(N+1,N+1+now,cmp);
	//	printf("{");
	//	for(int j=1;j<=min(10000,fac[i]);++j)
		{
//			printf("{");
	//		for(int k=1;k<i;++k)
			{
//				printf("%d ",N[j].num[k]);
//				if(k!=i-1)printf(",");
			}
//			printf("}");
//			if(j!=min(10000,fac[i]))printf(",");
//			printf("\n");
		}
//		printf("},\n");
	}
//	printf("};\n");
	return 0;
}
