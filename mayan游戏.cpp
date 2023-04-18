#include<cstdio>
using namespace std;
int qp[5][7],movex[6],movey[6],move[6];
int n,now;
void dfs(int x,int y,int fx)
{
	copy(); 
	

} 
int main()
{
	scanf("%d",&n);
	for(int i=0;i<5;++i)
	{
		int sum=0,t;
		scanf("%d",&t);
		while(t)
		{
			qp[i][sum]=t;
			++sum;
			scanf("%d",&t);
		}
	}
	for(int i=0;i<5;++i)
		for(int j=0;qp[i][j];++j)
		{
			dfs(i,j,1);
			dfs(i,j,-1);
		}
	return 0;
}
