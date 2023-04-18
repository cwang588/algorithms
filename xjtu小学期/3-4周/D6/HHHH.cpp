#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,q,th,caoz,x;
int resto[maxn+5],ne[maxn+5],t[maxn+5],len,res;
int pusht[maxn+5];
void add(int x,int y)
{
	ne[len]=resto[x];
	resto[x]=len;
	t[len]=y;
	len++;
} 
int buf[40];
struct point
{
	int va;
	int ord;
	point(int v,int i):va(v),ord(i){}
	friend bool operator < (const point &a, const point &b)
	{
    	return a.va < b.va;
	}
};
int dfs(int res)
{
	pusht[res]=res;
	bool flg=false;
	for(int i=resto[res];i!=-1;i=ne[i])
	{
		flg=true;
		pusht[res]=min(pusht[res],dfs(t[i]));
	}
	for(int i=resto[res];i!=-1;i=ne[i])
		pusht[res]=min(pusht[res],t[i]);
	if(flg)
		return pusht[res];
	return pusht[res]=res;
}
int pic[maxn+5],cnt,ran[maxn+5];
void fpic(int res)
{
	int th=0;
	vector<point>res2;
	for(int i=resto[res];i!=-1;i=ne[i])
	{
		th++;
		int u=t[i];
		res2.push_back(point(pusht[u],u));
	}
	sort(res2.begin(),res2.end());
	for(int i=0;i<th;i++){
		fpic(res2[i].ord);
	}
	pic[++cnt]=res;
}
struct cmpp
{
	bool operator()(int &A,int &B)
	{
		return ran[A]>ran[B];
	}
};
priority_queue <int,vector<int>,cmpp> pq;
int fat[maxn+5][30],ok[maxn+5];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		pusht[i]=maxn;
	memset(resto,-1,sizeof(resto));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&th);
		if(!th)
			res=i;
		else
		{
			fat[i][0]=th;
			add(th,i);
		}
	}
	dfs(res);
	fpic(res);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			fat[i][j]=fat[fat[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
		ran[pic[i]]=i;
	for(int i=1;i<=n;i++)
		pq.push(i);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&caoz);
		if(caoz==1)
		{
			scanf("%d",&x);
			for(int j=1;j<=x;j++)
			{
				int th=pq.top();
				pq.pop();
				ok[th]=1;
				if(j==x)
					printf("%d\n",th);
			}
		}
		else
		{
			scanf("%d",&x);
			int th=0;
			int nx=x;
			for(int j=20;j>=0;j--)
			{
				if(fat[nx][j]&&ok[fat[nx][j]])
				{
					nx=fat[nx][j];
					th+=(1<<j);
				}
			}
			ok[nx]=0;
			pq.push(nx);
			printf("%d\n",th);		
		}
	}
	return 0;
}
