#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define N 100005
//#define int long long
using namespace std;
struct edge{
	int from,to,nxt;
}e[N<<1];
int n,Head[N],fa[N],son[N],dep[N],sz[N],id[N],top[N],cnt,f[N][25];
long long a[N],b[N],c[N];//cola[N<<2],colb[N<<2],colc[N<<2];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;--i){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
void dfs1(int now,int pre,int depth){
	fa[now]=f[now][0]=pre;
	for(int i=1;i<=20;++i)f[now][i]=f[f[now][i-1]][i-1];
	dep[now]=depth;
	sz[now]=1;
	int Max=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now,depth+1);
		sz[now]+=sz[to];
		if(sz[to]>Max){
			Max=sz[to];
			son[now]=to;
		}
	}
}
int cntt;
void dfs2(int now,int topf){
	id[now]=++cntt;
	top[now]=topf;
	if(son[now])dfs2(son[now],topf);
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==fa[now]||to==son[now])continue;
		dfs2(to,to);
	}
}
int lowbit(int x){
	return x&(-x);
}
void modifya(int x,long long k){
	if(!x)return;
	while(x<=n){
		a[x]+=k;
		x+=lowbit(x);
	}
}
void modifyb(int x,long long k){
	if(!x)return;
	while(x<=n){
		b[x]+=k;
		x+=lowbit(x);
	}
}
void modifyc(int x,long long k){
	if(!x)return;
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
}
long long querya(int x){
	long long re=0;
	while(x){
		re+=a[x];
		x-=lowbit(x);
	}
	return re;
}
long long queryb(int x){
	long long re=0;
	while(x){
		re+=b[x];
		x-=lowbit(x);
	}
	return re;
}
long long queryc(int x){
	long long re=0;
	while(x){
		re+=c[x];
		x-=lowbit(x);
	}
	return re;
}
//void push_col(int l,int r,int rt){
//	a[rt<<1]+=cola[rt];
//	a[rt<<1|1]+=cola[rt];
//	b[rt<<1]+=colb[rt];
//	b[rt<<1|1]+=colb[rt];
//	c[rt<<1]+=colc[rt];
//	c[rt<<1|1]+=colc[rt];
//	cola[rt<<1]+=cola[rt];
//	cola[rt<<1|1]+=cola[rt];
//	colb[rt<<1]+=colb[rt];
//	colb[rt<<1|1]+=colb[rt];
//	colc[rt<<1]+=colc[rt];
//	colc[rt<<1|1]+=colc[rt];
//	cola[rt]=colb[rt]=colc[rt]=0;
//}
//void modify(int l,int r,int rt,int nowl,int nowr,long long x,long long d){
//	if(nowl<=l&&r<=nowr){
//		a[rt]+=d*d;
//		cola[rt]+=d*d;
//		b[rt]+=x*d*2+(l-1)*d*d*2;
//		colb[rt]+=x*d*2+(l-1)*d*d*2;
//		c[rt]+=x*x+(l-1)*(l-1)*d*d+x*(1-l)*d*2;
//		colc[rt]+=x*x+(l-1)*(l-1)*d*d+x*(1-l)*d*2;
//		return;
//	}
//	push_col(l,r,rt);
//	int m=(l+r)>>1;
//	if(m>=nowl)modify(lson,nowl,nowr,x,d);
//	if(m<nowr)modify(rson,nowl,nowr,x+d*(m-l+1),d);
//}
//long long query(int l,int r,int rt,int pos){
//	if(l==r)return a[rt]*l*l+b[rt]*l+c[rt];
//	push_col(l,r,rt);
//	int m=(l+r)>>1;
//	if(pos<=m)return query(lson,pos);
//	else return query(rson,pos);
//}
void modifyrange(int x,int y){
	int z=lca(x,y),len=-2*dep[z]+dep[x]+dep[y]+1,lnow=0,rnow=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]>=dep[top[y]]){
			//modify(1,n,1,id[top[x]],id[x],lnow+dep[top[x]]-dep[x]+2,-1);
			long long X=lnow-dep[top[x]]+dep[x]+2,d=-1,l=id[top[x]];
			modifya(id[x]+1,-d*d);
			modifya(id[top[x]],d*d);
			modifyb(id[x]+1,-X*d*2-(1-l)*d*d*2);
			modifyb(id[top[x]],X*d*2+(1-l)*d*d*2);
			modifyc(id[x]+1,-X*X-(l-1)*(l-1)*d*d-X*(1-l)*d*2);
			modifyc(id[top[x]],X*X+(l-1)*(l-1)*d*d+X*(1-l)*d*2);
			lnow+=-dep[top[x]]+dep[x]+1;
			x=fa[top[x]];
		}
		else{
			//modify(1,n,1,id[top[y]],id[y],len-(rnow+dep[top[y]]-dep[y]+1),1);
			long long X=len-(rnow-dep[top[y]]+dep[y]+1),d=1,l=id[top[y]];
			modifya(id[y]+1,-d*d);
			modifya(id[top[y]],d*d);
			modifyb(id[y]+1,-X*d*2-(1-l)*d*d*2);
			modifyb(id[top[y]],X*d*2+(1-l)*d*d*2);
			modifyc(id[y]+1,-X*X-(l-1)*(l-1)*d*d-X*(1-l)*d*2);
			modifyc(id[top[y]],X*X+(l-1)*(l-1)*d*d+X*(1-l)*d*2);
			rnow+=-dep[top[y]]+dep[y]+1;
			y=fa[top[y]];
		}
	}
	if(dep[x]>=dep[y]){
		//modify(1,n,1,id[y],id[x],lnow+dep[x]-dep[y]+2,-1);
		long long X=lnow+dep[x]-dep[y]+2,d=-1,l=id[y];
		modifya(id[x]+1,-d*d);
		modifya(id[y],d*d);
		modifyb(id[x]+1,-X*d*2-(1-l)*d*d*2);
		modifyb(id[y],X*d*2+(1-l)*d*d*2);
		modifyc(id[x]+1,-X*X-(l-1)*(l-1)*d*d-X*(1-l)*d*2);
		modifyc(id[y],X*X+(l-1)*(l-1)*d*d+X*(1-l)*d*2);
	}
	else{
		//modify(1,n,1,id[x],id[y],len-(rnow+dep[y]-dep[x]+1),1);
		long long X=len-(rnow+dep[y]-dep[x]+1),d=1,l=id[x];
		modifya(id[y]+1,-d*d);
		modifya(id[x],d*d);
		modifyb(id[y]+1,-X*d*2-(1-l)*d*d*2);
		modifyb(id[x],X*d*2+(1-l)*d*d*2);
		modifyc(id[y]+1,-X*X-(l-1)*(l-1)*d*d-X*(1-l)*d*2);
		modifyc(id[x],X*X+(l-1)*(l-1)*d*d+X*(1-l)*d*2);
	}
}
long long query(int x){
	long long A=querya(id[x]),B=queryb(id[x]),C=queryc(id[x]);
	return A*id[x]*id[x]+B*id[x]+C;
}
long long ans[100005];
void xg(int x,int y){
	int z=lca(x,y),len=-2*dep[z]+dep[x]+dep[y]+1;
	long long now=0;
	while(x!=z){
		++now;
		ans[x]+=now*now;
		x=fa[x];
	}
	++now;
	ans[x]+=now*now;
	now=0;
	while(y!=z){
		++now;
		ans[y]+=(len-now+1)*(len-now+1);
		y=fa[y];
	}
}
int main(){
	//ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	int m;
	cin>>m;
	for(int i=1;i<=m;++i){
		int t;
		cin>>t;
		//t=rand()%2+1;
		if(t==1){
			int x,y;
			cin>>x>>y;
			//x=rand()%n+1,y=rand()%n+1;
			//cout<<t<<" "<<x<<" "<<y<<endl;
			modifyrange(x,y);
			//xg(x,y);
		//	long long tmp=query(2);
		//	cout<<tmp<<" "<<ans[2]<<endl;
		}
		else{
			int x;
			cin>>x;
			//x=rand()%n+1;
		//	cout<<t<<" "<<x<<endl;
			cout<<query(x)<<endl;
//			long long tmp=query(x);
//			if(tmp!=ans[x]){
//				cout<<"WA!\n"<<endl;
//				cout<<tmp<<" "<<ans[x]<<endl;
//				break;
//			}
		}
	}
	return 0;
}
