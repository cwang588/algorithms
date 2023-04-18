#include<bits/stdc++.h>
//#define int long long
using namespace std;
const long long INF=214748364711451466;
long long a[200005];
struct edge{
	int from,to,nxt;
}e[400005];
int cnt,Head[200005],rt,size[200005],maxp[200005],sum;
long long ans;
bool usd[200005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void getrt(int now,int pre){
	size[now]=1;
	maxp[now]=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to]||to==pre)continue;
		getrt(to,now);
		size[now]+=size[to];
		maxp[now]=max(maxp[now],size[to]);
	}
	maxp[now]=max(maxp[now],sum-size[now]);
	if(maxp[now]<maxp[rt])rt=now;
}
int num,numm;
pair<long long,long long>tmp[200005],tmpp[200005];
struct node{
	int l,r,sz,key;
	long long val;
}T[200005];
int nodecnt,root;
inline int newnode(long long val){
	++nodecnt;
	T[nodecnt].l=T[nodecnt].r=0;
	T[nodecnt].val=val;
	T[nodecnt].sz=1;
	T[nodecnt].key=32768*rand()%32768+rand()%32768;
	return nodecnt;
}
void update(int now){
	T[now].sz=T[T[now].l].sz+T[T[now].r].sz+1;
}
void split_value(int now,long long val,int &x,int &y){
	if(!now)x=y=0;
	else{
		if(T[now].val<=val){
			x=now;
			split_value(T[now].r,val,T[now].r,y);
		}
		else{
			y=now;
			split_value(T[now].l,val,x,T[now].l);
		}
		update(now);
	}
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(T[x].key>T[y].key){
		T[x].r=merge(T[x].r,y);
		update(x);
		return x;
	}
	else{
		T[y].l=merge(x,T[y].l);
		update(y);
		return y;
	}
}
int x,y;
void insert(long long val){
	split_value(root,val,x,y);
	root=merge(merge(x,newnode(val)),y);
}
int getans(long long val){
	split_value(root,val,x,y);
	int re=T[x].sz;
	root=merge(x,y);
	return re;
}
void getdis(int now,int pre,long long tot,long long Max){
	tot+=a[now];
	Max=max(Max,a[now]);
	if(Max*2<tot)++ans;
	++num;
	tmp[num].first=Max,tmp[num].second=tot;
	++numm;
	tmpp[numm].first=Max,tmpp[numm].second=tot;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to]||to==pre)continue;
		getdis(to,now,tot,Max);
	}
}
void calc(int now){
	numm=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to])continue;
		num=0;
		getdis(to,now,a[now],a[now]);
		sort(tmp+1,tmp+1+num);
		nodecnt=root=0;
		insert(INF);
		insert(-INF);
		for(int j=1;j<=num;++j){
			long long Max=tmp[j].first,sum=tmp[j].second;
			ans-=j-getans(a[now]+2*Max-sum);
			insert(sum);
		}
	}
	nodecnt=root=0;
	insert(INF);
	insert(-INF);
	sort(tmpp+1,tmpp+1+numm);
	for(int i=1;i<=numm;++i){
		long long Max=tmpp[i].first,sum=tmpp[i].second;
		ans+=i-getans(a[now]+2*Max-sum);
		insert(sum);
	}
}
void solve(int now){
	usd[now]=true;
	calc(now);
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to])continue;
		sum=size[to];
		maxp[rt=0]=2147483647;
		getrt(to,0);
		solve(rt);
	}
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		cnt=ans=0;
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]),Head[i]=0,usd[i]=false;
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		maxp[rt]=sum=n;
		getrt(1,0);
		solve(rt);
		printf("%lld\n",ans);
	}
	return 0;
}
