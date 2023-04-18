#include<bits/stdc++.h>
using namespace std;
struct length
{
	int sum,id;
}t[5];
bool cmp(length a,length b)
{
	return a.sum<b.sum;
}
bool usd[105][105][105];
void print()
{
	if(t[1].id==1&&t[2].id==2&&t[3].id==3)
	{
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				for(int k=0;k<=100;++k)
					if(usd[i][j][k])
						printf("%d %d %d\n",i,j,k); 
	}
	if(t[1].id==1&&t[2].id==3&&t[3].id==2)
	{
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				for(int k=0;k<=100;++k)
					if(usd[i][j][k])
						printf("%d %d %d\n",i,k,j); 
	}
	if(t[1].id==2&&t[2].id==1&&t[3].id==3)
	{
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				for(int k=0;k<=100;++k)
					if(usd[i][j][k])
						printf("%d %d %d\n",j,i,k); 
	}
	if(t[1].id==2&&t[2].id==3&&t[3].id==1)
	{
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				for(int k=0;k<=100;++k)
					if(usd[i][j][k])
						printf("%d %d %d\n",j,k,i); 
	}
	if(t[1].id==3&&t[2].id==1&&t[3].id==2)
	{
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				for(int k=0;k<=100;++k)
					if(usd[i][j][k])
						printf("%d %d %d\n",k,i,j); 
	}
	if(t[1].id==3&&t[2].id==2&&t[3].id==1)
	{
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				for(int k=0;k<=100;++k)
					if(usd[i][j][k])
						printf("%d %d %d\n",k,j,i); 
	}
}
int main()
{
	t[1].id=1;
	t[2].id=2;
	t[3].id=3;
	scanf("%d%d%d",&t[3].sum,&t[1].sum,&t[2].sum);
	sort(t+1,t+4,cmp);
	int a=t[1].sum,b=t[2].sum,c=t[3].sum;
	if(a*b<c)
		return !printf("-1\n");
	if(c==2&&a==2&&b==2)
		return !printf("2\n0 0 0\n1 1 1\n");
	if(a==2)
	{
		if(a+b-1>c&&c-a>=1)
			return !printf("-1\n");
	}
	for(int i=0;i<a;++i)
		usd[i][0][0]=true;
	for(int i=0;i<b;++i)
		usd[0][i][0]=true;	
	if(a+b-1<=c)
	{
		int re=c-(a+b-1);
		for(int i=1;i<a;++i)
			for(int j=1;j<b;++j)
			{
				if(!re)
					break;
				usd[i][j][0]=true;
				--re;
			}
		printf("%d\n",c);
	}
	else
	{
		int re=a+b-1-c;
		int tot=a+b-1;
		for(int i=1;2*i<=re+1;++i)
		{
			usd[a-i][0][0]=false;
			usd[0][b-i][0]=false;
			usd[0][0][i]=true;
			--tot;
		}
		if(re%2)
		{
			usd[1][1][0]=true;
			++tot;
		}
		printf("%d\n",tot);
	}
	print();
	return 0;
}
