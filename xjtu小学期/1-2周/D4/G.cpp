#include<bits/stdc++.h>
using namespace std;
#define MAXN 7
#define MAXM
#define INF 0x3f3f3f3f
typedef long long int LL;
const int Input_rule[8][8]=
{
	{0,0,0,0,0,0,0,0},
	{2,3,5,0,0,0,0,0},
	{2,3,5,0,0,0,0,0},
	{7,1,2,3,4,5,6,7},
	{2,3,5,0,0,0,0,0},
	{7,1,2,3,4,5,6,7},
	{2,3,5,0,0,0,0,0},
	{2,3,5,0,0,0,0,0},
}; 
const int rule[9][3]=
{
	{0,0,0},
	{3,1,0},
	{5,1,0},
	{3,0,1},
	{5,0,1},
	{5,1,1},
	{3,1,1},
	{5,0,0},
	{3,0,0}
};
const int back[9]={0,6,5,8,7,2,1,4,3};
const char opp[9]={'0','A','B','C','D','E','F','J','M'};
int Map[MAXN+5][MAXN+5];
char road[100];int cnt=0;
int N;
int h()
{
	int num[5];
	memset(num,0,sizeof(num));
	for(int i=3;i<=5;++i)
		for(int j=3;j<=5;++j)
			if(!(i==4&&j==4))++num[Map[i][j]];
	int Smax=-INF;
	for(int i=1;i<=3;++i)
		Smax=max(Smax,num[i]);
	return 8-Smax;
}
void rotate(int now)
{
	bool CorR=rule[now][1],dir=rule[now][2];
	if(CorR)
	{
		int col=rule[now][0];
		if(dir==0)
		{
			for(int i=0;i<N;++i)
				Map[i][col]=Map[i+1][col];
			Map[N][col]=Map[0][col];
			Map[0][col]=0;
		}
		else
		{
			for(int i=N+1;i>1;--i)
				Map[i][col]=Map[i-1][col];
			Map[1][col]=Map[N+1][col];
			Map[N+1][col]=0;
		}
	}
	else
	{
		int row=rule[now][0];
		if(dir==0)
		{
			for(int i=0;i<N;++i)
				Map[row][i]=Map[row][i+1];
			Map[row][N]=Map[row][0];
			Map[row][0]=0;
		}
		else
		{
			for(int i=N+1;i>1;--i)
				Map[row][i]=Map[row][i-1];
			Map[row][1]=Map[row][N+1];
			Map[row][N+1]=0;
		}
	}
}
bool dfs(int dep,int &Maxdep)
{
	if(dep+h()>Maxdep)return 0;
	if(h()==0)return 1;
	for(int i=1;i<9;++i)
	{
		rotate(i);
		road[++cnt]=opp[i];
		if(dfs(dep+1,Maxdep))
			return 1;
		--cnt;
		rotate(back[i]);
	}
	return 0;
}
int main()
{
	N=7;
	int i,j,n;
	scanf("%d",&Map[1][3]);
	cnt=0;
	n=2;
	i=1;
	while(i<=N)
	{
		j=Input_rule[i][n++];
		scanf("%d",&Map[i][j]);
		if(n>Input_rule[i][0])
		{
			n-=Input_rule[i][0];
			++i;
		}
	}
	int ans;
	for(ans=0;;++ans)
		if(dfs(0,ans))
			break;
	cout<<cnt<<endl;
	for(i=1;i<=cnt;++i)
		cout<<road[i];	
}		
