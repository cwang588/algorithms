#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
string biao[15][15];
bool usd[27];
int n;
char zm[15];
int pos[27];
int pl[15];
int cnt;
bool you[15];
bool pd(int i,int j)
{
	int t=pl[pos[biao[i][1][0]-'A'+1]]+pl[pos[biao[1][j][0]-'A'+1]];
	int a=t/(n-1),b=t%(n-1);
	if(a==pl[pos[biao[i][j][0]-'A'+1]]&&b==pl[pos[biao[i][j][1]-'A'+1]])
		return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>biao[i][j];
			if((i==1)&&biao[i][j]!="+")
			{
				if(!usd[biao[i][j][1]])
				{
					zm[++cnt]=biao[i][j][0];
					usd[biao[i][j][0]]=true;
					pos[biao[i][j][0]-'A'+1]=cnt;
				}
			}
		}
	for(int i=2;i<=n;++i)
	{
		int sum=0;
		for(int j=2;j<=n;++j)
		{
			if(biao[i][j][1])
				++sum;
		}
		if(you[sum])
			return !printf("ERROR!");
		pl[pos[biao[i][1][0]-'A'+1]]=sum;
	}
	for(int i=2;i<=n;++i)
		for(int j=2;j<=n;++j)
		{
			if(biao[i][j][1])
			{
				//if(pl[pos[biao[i][1][0]-'A'+1]]+pl[pos[biao[1][j][0]-'A'+1]]!=10*pl[pos[biao[i][j][0]-'A'+1]]+pl[pos[biao[i][j][1]-'A'+1]])
				if(!pd(i,j))
				{
				//	printf("%d %d %d %d %d %d",i,j,pl[pos[biao[i][1][0]-'A'+1]],pl[pos[biao[1][j][0]-'A'+1]],pl[pos[biao[i][j][0]-'A'+1]],pl[pos[biao[i][j][1]-'A'+1]]);
					return !printf("ERROR!");
				}
			}
			else
			{
				if(pl[pos[biao[i][1][0]-'A'+1]]+pl[pos[biao[1][j][0]-'A'+1]]!=pl[pos[biao[i][j][0]-'A'+1]])
				{
				//	printf("%d %d %d %d %d",i,j,pl[pos[biao[i][1][0]-'A'+1]],pl[pos[biao[1][j][0]-'A'+1]],pl[pos[biao[i][j][0]-'A'+1]]);
					return !printf("ERROR!");	
				}
			}
		}
	for(int i=1;i<n;++i)
		printf("%c=%d ",zm[i],pl[i]);
	printf("\n%d",n-1);
	return 0;
}
