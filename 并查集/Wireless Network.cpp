#include<cstdio>
#include<iostream>
using namespace std;
struct eedge
{
	int frm,too,nxt;
}e[10000005];
int Head[10005],cnt;
bool ky[1005][1005];
int x[10005],y[10005];
void aadd(int a,int b)
{
	++cnt;
	e[cnt].frm=a;
	e[cnt].too=b;
	e[cnt].nxt=Head[a];
	Head[a]=cnt;
}
int dis(int a,int b)
{
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
int fa[10005];
bool usd[10005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int main()
{
//	ios::sync_with_stdio(false); 
	int n,d; 
	cin>>n>>d;
	d*=d;
	for(int i=1;i<=n;++i)fa[i]=i,Head[i]=-1;
	for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(dis(i,j)<=d)
			{
				aadd(i,j);
				aadd(j,i);
//				ky[i][j]=true;
//				ky[j][i]=true;
			}
	char t;
	while(cin>>t)
	{
		if(t=='O')
		{
			int xx;
			cin>>xx;
			usd[xx]=true;
			for(int i=Head[xx];i!=-1;i=e[i].nxt)
			{
				if(usd[e[i].too])
				{
					int rrrr=getfa(xx),rrrrr=getfa(e[i].too);
					if(rrrr!=rrrrr)fa[rrrrr]=rrrr;
				}
			}
		}
		else if(t=='S')
		{
			int xx,yy;
			cin>>xx>>yy;
			int rrrr=getfa(xx),rrrrr=getfa(yy);
			if(rrrr==rrrrr&&usd[xx]&&usd[yy])cout<<"SUCCESS"<<endl;
			else cout<<"FAIL"<<endl;
		}
	}
	return 0;
}
