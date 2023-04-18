#include<bits/stdc++.h>
using namespace std;
const int INF=1000000000;
struct query{
	int l,r,lw,rw,id,ans,lca,lo,ro,anss;
}q[300005];
bool cmp(query x,query y){
	if(x.lw!=y.lw)return x.lw<y.lw;
	return x.rw<y.rw;
}
bool cmpp(query x,query y){
	return x.id<y.id;
}
int a[300005],num,st[100005],ed[100005],v[100005];
struct edge{
	int from,to,nxt,value;
}e[200005];
int Head[100005],cnt,fa[100005][25],depth[100005];
int sum[100005],summ[100005];
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre){
	depth[now]=depth[pre]+1;
	fa[now][0]=pre;
	for(int i=1;i<=19;++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		v[to]=e[i].value;
		a[++num]=to;
		st[to]=num;
		dfs(to,now);
		a[++num]=to;
		ed[to]=num;	
	}
} 
int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=19;i>=0;--i){
		if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
set<int>s;
int dis[105][105],cntt[105],xx[105],yy[105],zz[105];
int main(){
	bool ky=true;
	while(ky){
		num=cnt=0;
		memset(a,0,sizeof(a));
		memset(Head,0,sizeof(Head));
		memset(sum,0,sizeof(sum));
		memset(summ,0,sizeof(summ));
		memset(fa,0,sizeof(fa));
		memset(dis,0,sizeof(dis));
		memset(cntt,0,sizeof(cntt));
		int n,m,base;
		n=m=10;
		base=sqrt(n*2);
		for(int i=1;i<n;++i){
			int x,y,z;
			x=i+1;
			y=rand()%i+1;
			z=rand()%5;
			add(x,y,z);
			add(y,x,z);
			xx[i]=x;
			yy[i]=y;
			zz[i]=z;
			dis[x][y]=dis[y][x]=z;
		}
		v[0]=v[1]=n+1;
		dfs(1,0);
		for(int i=1;i<=m;++i){
			int l,r;
			l=rand()%n+1;
			r=rand()%n+1;
			q[i].lo=l;
			q[i].ro=r;
			if(st[l]>st[r])swap(l,r);
			int nowlca=lca(l,r);
			if(nowlca==l){
				q[i].l=st[l]+1;
				q[i].r=st[r];
			}
			else{
				q[i].l=ed[l];
				q[i].r=st[r];
			}
			q[i].lca=nowlca; 
			q[i].lw=(q[i].l-1)/base+1;
			q[i].rw=(q[i].r-1)/base+1;
			q[i].id=i;
		}
		sort(q+1,q+1+m,cmp);
		int l=0,r=0,tmpans=0;
		for(int i=0;i<=n;++i)s.insert(i);
		for(int i=1;i<=m;++i){
			while(r<q[i].r){
				++r;
				if(v[a[r]]>=n)continue;
				summ[a[r]]=(summ[a[r]]+1)%2;
				if(!summ[a[r]]){
					--sum[v[a[r]]];
					if(!sum[v[a[r]]])s.insert(v[a[r]]);
				}
				else{
					++sum[v[a[r]]];
					if(sum[v[a[r]]]==1)s.erase(v[a[r]]);
				}
			}
			while(l>q[i].l){
				--l; 
				if(v[a[l]]>=n)continue;
				summ[a[l]]=(summ[a[l]]+1)%2;
				if(!summ[a[l]]){
					--sum[v[a[l]]];
					if(!sum[v[a[l]]])s.insert(v[a[l]]);
				}
				else{
					++sum[v[a[l]]];
					if(sum[v[a[l]]]==1)s.erase(v[a[l]]);
				}
			}
			while(r>q[i].r){
				if(v[a[r]]>=n)goto next1;
				summ[a[r]]=(summ[a[r]]+1)%2;
				if(!summ[a[r]]){
					--sum[v[a[r]]];
					if(!sum[v[a[r]]])s.insert(v[a[r]]);
				}
				else{
					++sum[v[a[r]]];
					if(sum[v[a[r]]]==1)s.erase(v[a[r]]);
				}
				next1:--r;
			}
			while(l<q[i].l){
				if(v[a[l]]>=n)goto next2;
				summ[a[l]]=(summ[a[l]]+1)%2;
				if(!summ[a[l]]){
					--sum[v[a[l]]];
					if(!sum[v[a[l]]])s.insert(v[a[l]]);
				}
				else{
					++sum[v[a[l]]];
					if(sum[v[a[l]]]==1)s.erase(v[a[l]]);
				}
				next2:++l;
			}
//			if(v[q[i].lca]<n){
//				summ[q[i].lca]=(summ[q[i].lca]+1)%2;
//				if(!summ[q[i].lca]){
//					--sum[v[q[i].lca]];
//					if(!sum[v[q[i].lca]])s.insert(v[q[i].lca]);
//				}
//				else{
//					++sum[v[q[i].lca]];
//					if(sum[v[q[i].lca]]==1)s.erase(v[q[i].lca]);
//				}
//			}
			q[i].ans=*s.begin();
//			if(v[q[i].lca]<n){
//				summ[q[i].lca]=(summ[q[i].lca]+1)%2;
//				if(!summ[q[i].lca]){
//					--sum[v[q[i].lca]];
//					if(!sum[v[q[i].lca]])s.insert(v[q[i].lca]);
//				}
//				else{
//					++sum[v[q[i].lca]];
//					if(sum[v[q[i].lca]]==1)s.erase(v[q[i].lca]);
//				}
//			}
			memset(cntt,0,sizeof(cntt));
			int nowl=q[i].lo,nowr=q[i].ro;
			while(nowl!=q[i].lca){
				++cntt[dis[nowl][fa[nowl][0]]];
				nowl=fa[nowl][0];
			}
			while(nowr!=q[i].lca){
				++cntt[dis[nowr][fa[nowr][0]]];
				nowr=fa[nowr][0];
			}
			for(int j=0;j<=100;++j){
				if(!cntt[j]){
					q[i].anss=j;
					break;
				}
			}
		}
		sort(q+1,q+1+m,cmpp);
		for(int i=1;i<=m;++i){
			if(q[i].ans!=q[i].anss){
				ky=false;
				break;
			}
		}
		if(!ky){
			cout<<n<<" "<<m<<endl;
			for(int i=1;i<n;++i)cout<<xx[i]<<" "<<yy[i]<<" "<<zz[i]<<endl;
			for(int i=1;i<=m;++i)cout<<q[i].lo<<" "<<q[i].ro<<endl;
			for(int i=1;i<=m;++i)cout<<q[i].ans<<" "<<q[i].anss<<endl;
		}
		else cout<<"ok"<<endl;
	}
	return 0;
}
