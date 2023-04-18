#include<bits/stdc++.h>
using namespace std;
char a[105][105],s[105];
struct point{
	int x,y,k;
};
struct edge{
	int from,to,nxt,value;
}e[2000005];
int cnt,Head[1000005],dis[1000005];
bool usd[1000005];
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int getid(int x,int y,int k){
	return x*10000+y*100+k;
}
point rep(int id){
	point tmp;
	tmp.x=id/10000;
	id%=10000;
	tmp.y=id/100;
	tmp.k=id%100;
	return tmp;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){
	int n,m;
	cin>>n>>m;
	int sx,sy,ex,ey;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			if(a[i][j]=='R'){
				sx=i;
				sy=j;
			}
			if(a[i][j]=='E'){
				ex=i;
				ey=j;
			}
		}
	}
	cin>>(s+1);
	int k=strlen(s+1);
	int ans=2147483647;
	int tox,toy,tok,id;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]=='#')continue;
			for(int o=1;o<=k+1;++o){
				int nowid=getid(i,j,o);
				if(o<=k){
					tox=i,toy=j,tok=o+1;
					id=getid(tox,toy,tok);
					add(nowid,id,1);
					if(s[o]=='U'){
						tox=i-1;
						if(i==1||a[i-1][j]=='#')tox=i;
						toy=j;
						tok=o+1;
						id=getid(tox,toy,tok);
						add(nowid,id,0);
					}
					if(s[o]=='D'){
						tox=i+1;
						if(i==n||a[i+1][j]=='#')tox=i;
						toy=j;
						tok=o+1;
						id=getid(tox,toy,tok);
						add(nowid,id,0);
					}
					if(s[o]=='L'){
						toy=j-1;
						if(j==1||a[i][j-1]=='#')toy=j;
						tox=i;
						tok=o+1;
						id=getid(tox,toy,tok);
						add(nowid,id,0);
					}
					if(s[o]=='R'){
						toy=j+1;
						if(j==m||a[i][j+1]=='#')toy=j;
						tox=i;
						tok=o+1;
						id=getid(tox,toy,tok);
						add(nowid,id,0);
					}
				}
				tox=i-1;
				if(i==1||a[i-1][j]=='#')tox=i;
				toy=j;
				tok=o;
				id=getid(tox,toy,tok);
				add(nowid,id,1);
				tox=i+1;
				if(i==n||a[i+1][j]=='#')tox=i;
				toy=j;
				tok=o;
				id=getid(tox,toy,tok);
				add(nowid,id,1);
				toy=j-1;
				if(j==1||a[i][j-1]=='#')toy=j;
				tox=i;
				tok=o;
				id=getid(tox,toy,tok);
				add(nowid,id,1);
				toy=j+1;
				if(j==m||a[i][j+1]=='#')toy=j;
				tox=i;
				tok=o;
				id=getid(tox,toy,tok);
				add(nowid,id,1);
			}
		}
	}
	for(int i=1;i<=1000000;++i)dis[i]=19260817;
	dis[getid(sx,sy,1)]=0;
	q.push(make_pair(0,getid(sx,sy,1)));
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(!usd[now]){
			usd[now]=true;
			for(int i=Head[now];i;i=e[i].nxt){
				int to=e[i].to;
				if(dis[to]>dis[now]+e[i].value){
					dis[to]=dis[now]+e[i].value;
					q.push(make_pair(dis[to],to));
				}
			}
		}
	}
	for(int i=1;i<=k+1;++i){
		int nowid=getid(ex,ey,i);
		ans=min(ans,dis[nowid]);
	}
	cout<<ans;
	return 0;
}
