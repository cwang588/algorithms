#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int dis[1005][1005],n;
struct bian{
	int x,y,value;
}E[6000050];
struct edge{
	int from,to,nxt;
}e[6000005];
int cnt,Head[5000005],pnum,value[5000005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool cmp(bian a,bian b){
	return a.value>b.value;
}
int getid(int x,int y){
	return (x-1)*n+y;
}
int fa[3000005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
} 
int f[3000005][25],depth[3000005];
void dfs(int now,int pre){
	f[now][0]=pre;
	depth[now]=depth[pre]+1;
	for(int i=1;i<=23;++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfs(to,now);
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=23;i>=0;--i)if(depth[f[x][i]]>=depth[y])x=f[x][i];
	if(x==y)return x;
	for(int i=23;i>=0;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>s[i][j];
			if(s[i][j]!='#')dis[i][j]=10005;
		}
	}
	for(int i=1;i<=n*n*5;++i)fa[i]=i;
	for(int i=1;i<=n;++i){
		int now=0;
		for(int j=1;j<=n;++j){
			if(s[i][j]=='#')now=j;
			else dis[i][j]=min(dis[i][j],j-now);
		}
	}
	for(int i=1;i<=n;++i){
		int now=n+1;
		for(int j=n;j>=1;--j){
			if(s[i][j]=='#')now=j;
			else dis[i][j]=min(dis[i][j],now-j);
		}
	}
	for(int i=1;i<=n;++i){
		int now=0;
		for(int j=1;j<=n;++j){
			if(s[j][i]=='#')now=j;
			else dis[j][i]=min(dis[j][i],j-now);
		}
	}
	for(int i=1;i<=n;++i){
		int now=n+1;
		for(int j=n;j>=1;--j){
			if(s[j][i]=='#')now=j;
			else dis[j][i]=min(dis[j][i],now-j);
		}
	}	
	int num=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<n;++j){
			++num;
			E[num].x=getid(i,j);
			E[num].y=getid(i,j+1);
			E[num].value=min(dis[i][j],dis[i][j+1]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<n;++j){
			++num;
			E[num].x=getid(j,i);
			E[num].y=getid(j+1,i);
			E[num].value=min(dis[j][i],dis[j+1][i]);
		}
	}
	sort(E+1,E+1+num,cmp);
	pnum=n*n;
	for(int i=1;i<=num;++i){
		int r1=getfa(E[i].x),r2=getfa(E[i].y);
		if(r1==r2)continue;
		++pnum;
		Merge(r1,pnum);
		Merge(r2,pnum);
		value[pnum]=E[i].value;
		add(pnum,r1);
		add(pnum,r2);
	}
	dfs(pnum,0);
	int m;
	cin>>m;
	for(int i=1;i<=m;++i){
		int xa,xb,ya,yb;
		cin>>xa>>ya>>xb>>yb;
		cout<<max(0,2*value[lca(getid(xa,ya),getid(xb,yb))]-1)<<endl;
	}
	return 0;
}
