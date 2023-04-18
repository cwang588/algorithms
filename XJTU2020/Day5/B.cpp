#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
}p[20];
double l[25];
int m;
bool usd[25];
int ans;
int C(int x)
{
	return x*(x-1)/2;
}
bool cmp(double x,double y)
{
	return x<y;
}
int t[25];
int Cnt;
double tt[25];
void dfs(int Now)
{
	if(Now==m)
	{
		int cnt=0;
	//	for(int i=1;i<=m/2;++i)tt[i]=l[i];
		for(int i=1;i<=m;i+=2)
		{
			int ttx=p[t[i+1]].x-p[t[i]].x,tty=p[t[i+1]].y-p[t[i]].y;
			if(ttx==0)l[++cnt]=100000.0;
			else 
			{
				if(tty==0)l[++cnt]=0;
				else l[++cnt]=(double)tty/(double)ttx;
			}
		}
		sort(l+1,l+1+m/2,cmp);
	//	for(int i=1;i<=m;++i)cout<<l[i]<<' ';
	//	cout<<endl;
		int now=1,tmp=0;
		for(int i=2;i<=m/2;++i)
		{
			if((l[i]-l[i-1])<0.00000001&&(l[i]-l[i-1])>-0.00000001)++now;
			//if(l[i]==l[i-1])++now;
			else
			{
				tmp+=C(now);
				now=1;		
			}
		}
		tmp+=C(now);
		ans=max(ans,tmp);
//		if(tmp==16)
//		{
//			for(int i=1;i<=16;++i)
//				cout<<tt[i]<<' ';
//			for(int i=2;i<=16;i+=2)
//				cout<<(double)(p[t[i]].y-p[t[i-1]].y)/(double)(p[t[i]].x-p[t[i-1]].x)<<' ';
//			cout<<endl;
//		}
		return;
	}
	int nxt;
	for(int i=1;i<=m;++i)
	{
		if(!usd[i])
		{
			nxt=i;
			break;
		}
	}
	usd[nxt]=true;
	t[++Cnt]=nxt;
	for(int i=nxt+1;i<=m;++i)
	{
		if(!usd[i])
		{
			int tx=p[nxt].x-p[i].x,ty=p[nxt].y-p[i].y;
			if(tx==0)l[Now/2+1]=100000000.0;
			else 
			{
				if(ty==0)l[Now/2+1]=0.0;
				else l[Now/2+1]=(double)ty/(double)tx;
			}
			usd[i]=true;
			t[++Cnt]=i;
			dfs(Now+2);
			usd[i]=false;
			--Cnt;
		}
	}
	usd[nxt]=false;
	--Cnt;
}
int main()
{
	scanf("%d",&m);	
	for(int i=1;i<=m;++i)scanf("%d%d",&p[i].x,&p[i].y);
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
