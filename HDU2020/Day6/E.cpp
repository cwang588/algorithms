#include<bits/stdc++.h>
using namespace std;
set<long long>f[18][18];
int a[]={0,1,1,4,5,1,4,1,9,1,9,1,1,4,5,1,4,1,9,1,9},ans[5005];
int getnum(int i,int j)
{
	if(j-i+1>4)return 50001;
	int re=0;
	for(int x=i;x<=j;++x)re=re*10+a[x];
	return re;
}
int main()
{
	freopen("ans.txt","w",stdout);
	for(int i=1;i<=15;++i)
		for(int j=i;j<=15;++j)
		{
			int tmp=getnum(i,j);
			if(tmp<=5000)f[i][j].insert(tmp);
		}
	for(int j=1;j<=13;++j)
		for(int i=1;i<=13;++i)
		{
			if(i+j-1>13)break;
			int r=i+j-1;
			for(int k=i;k<r;++k)
			{
				for(auto x=f[i][k].begin();x!=f[i][k].end();++x)
					for(auto y=f[k+1][r].begin();y!=f[k+1][r].end();++y)
					{
						long long t1=*x+*y,t2=(*x)*(*y);
						if(t1<=5000)f[i][r].insert(*x+*y);
						if(t2<=5000)f[i][r].insert((*x)*(*y));
					}
			}
		}
		
	for(int i=1;i<=5000;++i)
	{
		for(int j=1;j<=15;++j)
		{
			if(f[1][j].count(i))
			{
				ans[i]=j;
				break;
			}	
		}
	}
	printf("int ans[]={\n");
	for(int i=1;i<=5000;++i)
	{
		printf("%d,",ans[i]);
		if(i%25==0)printf("\n");
	}
	printf("};");
	return 0;
} 
