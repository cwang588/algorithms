#include<bits/stdc++.h>
using namespace std;
char s[100005];
int tmp[100005][3];
int pos[100005];
int cishu[35][15][50];
bool judge(int x,int y,int z)
{
	x%=100;
	if(z<=2000||z>2020||y<=0||y>12||x<=0||x>31)return false;
	if(z%4)
	{
		if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)return true;
		if(y==2)return x<=28;
		return x<=30;
	}
	else 
	{
		if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)return true;
		if(y==2)return x<=29;
		return x<=30;
	}
}
int main()
{
	cin>>(s+1);
	int n=strlen(s+1);
	int tot=0,num=0;
	for(int i=1;i<=n;++i)if(s[i]=='-')pos[++tot]=i;
	pos[++tot]=n+1;
	for(int i=1;i<=tot;++i)
	{
		++num;
		if(pos[i]-pos[i-1]-1>4)
		{
			tmp[num][0]=0;
			int t=0;
			for(int j=pos[i-1]+1;j<=pos[i-1]+4;++j)	
				t=t*10+s[j]-'0';
			tmp[num][1]=t;
			t=0;
			for(int j=pos[i]-3;j<=pos[i];++j)
				t=t*10+s[j]-'0';
			tmp[num][2]=t;
			continue;
		}
		int now=0;
		for(int j=pos[i-1]+1;j<pos[i];++j)
			now=now*10+s[j]-'0';
		tmp[num][0]=tmp[num][1]=tmp[num][2]=now;
	}
	for(int i=1;i<=num-2;++i)
	{
		if(judge(tmp[i][2],tmp[i+1][0],tmp[i+2][1]))
			++cishu[tmp[i][2]%100][tmp[i+1][0]][tmp[i+2][1]%2000];
	}
	int Max=0,x,y,z;
	for(int i=1;i<=31;++i)
		for(int j=1;j<=12;++j)
			for(int k=1;k<=20;++k)
			{
				if(cishu[i][j][k]>Max)
				{
					Max=cishu[i][j][k];
					x=i,y=j,z=k;
				}
			}
	if(x<10)printf("0%d-",x);
	else printf("%d-",x);
	if(y<10)printf("0%d-",y);
	else printf("%d-",y);
	printf("%d\n",z+2000);
	return 0;
}
