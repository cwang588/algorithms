#include<bits/stdc++.h>
using namespace std;
namespace treap{
	struct node{
		int l,r,val,key,sz;
	}fhq[10000005];
	int cnt;
	inline int newnode(int val){
		fhq[++cnt].val=val;
		fhq[cnt].sz=1;
		fhq[cnt].key=32768*rand()%32768+rand()%32768;
		return cnt;
	}
	void update(int now){
		fhq[now].sz=fhq[fhq[now].l].sz+fhq[fhq[now].r].sz+1;
	}
	struct treap{	
		int root,x,y,z;
		treap():root(0),x(0),y(0),z(0){}
		int size(){
			return fhq[root].sz;
		}
		void split_value(int now,int val,int &x,int &y){
			if(!now)x=y=0;
			else{
				if(fhq[now].val<=val){
					x=now;
					split_value(fhq[now].r,val,fhq[now].r,y);
				}
				else{
					y=now;
					split_value(fhq[now].l,val,x,fhq[now].l);
				}
				update(now);
			}
		}
		int merge(int x,int y){
			if(!x||!y)return x+y;
			if(fhq[x].key>fhq[y].key){
				fhq[x].r=merge(fhq[x].r,y);
				update(x);
				return x;
			}
			else{
				fhq[y].l=merge(x,fhq[y].l);
				update(y);
				return y;
			}
		}
		void insert(int val){
			split_value(root,val,x,y);
			root=merge(merge(x,newnode(val)),y);
		}
		void del(int val){
			split_value(root,val,x,z);
			split_value(x,val-1,x,y);
			y=merge(fhq[y].l,fhq[y].r);
			root=merge(merge(x,y),z);
		}
		int getrank(int val){
			split_value(root,val-1,x,y);
			int re=fhq[x].sz+1;
			root=merge(x,y);
			return re;
		}
		int getnum(int rank){
			int now=root;
			while(now){
				if(fhq[fhq[now].l].sz+1==rank)break;
				if(fhq[fhq[now].l].sz>=rank)now=fhq[now].l;
				else{
					rank-=fhq[fhq[now].l].sz+1;
					now=fhq[now].r;
				}
			}
			return fhq[now].val;
		}
		int getpre(int val){
			split_value(root,val-1,x,y);
			int now=x;
			while(fhq[now].r)now=fhq[now].r;
			int re=fhq[now].val;
			root=merge(x,y);
			return re;
		}
		int getnext(int val){
			split_value(root,val,x,y);
			int now=y;
			while(fhq[now].l)now=fhq[now].l;
			int re=fhq[now].val;
			root=merge(x,y);
			return re;
		}
	};
}
struct cities{
	cities():sz(0),now(0){}
	treap::treap s;
	int now;
	long long sz;
	bool operator<(const cities &b)const{
		return sz<b.sz;
	}
	void add(int x){
		s.insert(x);
	}
	int getnow(){
		return s.getnum(1+(now-1+s.size())%s.size());
	}
};
int cnt[500005];
cities c[500006];
struct query{
	int id,ans;
	long long k;
}q[500005];
bool cmp(query &a,query &b){
	return a.k<b.k;
}
bool cmpp(query &a,query &b){
	return a.id<b.id;
}
void dfs(int now,cities* a){
	if(!now)return;
	a->s.insert(treap::fhq[now].val);
	dfs(treap::fhq[now].l,a);
	dfs(treap::fhq[now].r,a);
}
cities* Merge(cities* a,cities* b){
	if(a->s.size()<b->s.size())swap(a,b);
	a->sz=max(a->sz,b->sz);
	a->now=0;
	dfs(b->s.root,a);
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		++cnt[t];
	}
	stack<cities*>pq;
	for(int i=1;i<=m;++i)c[cnt[i]].add(i);
	for(int i=n;i>=0;--i)if(c[i].s.size())c[i].sz=i,pq.push(&c[i]);
	for(int i=1;i<=k;++i)cin>>q[i].k,q[i].id=i;
	sort(q+1,q+1+k,cmp);
	long long cur=n;
	for(int i=1;i<=k;++i){
		long long gap=q[i].k-cur;
		if(!gap){
			q[i].ans=q[i-1].ans;
			continue;
		}
		while(gap){
			if(pq.size()==1){
				pq.top()->now=(pq.top()->now+gap)%(pq.top()->s.size());
				q[i].ans=pq.top()->getnow();	
				gap=0;
			}else{
				auto now=pq.top();
				pq.pop();
				long long tmp=now->now+1ll*now->sz*now->s.size()+gap;
				long long nxtsz=tmp/now->s.size();
				int nxtnow=tmp%now->s.size();
			//	if(nxtnow)--nxtsz;
				if(nxtsz<pq.top()->sz){
					now->now=nxtnow;
					now->sz=nxtsz;
					q[i].ans=now->getnow();	
					gap=0;
					pq.push(now);
				}else{	
					gap-=1ll*(pq.top()->sz-now->sz)*now->s.size()-now->now;
					if(!gap){
						now->now=0;
						q[i].ans=now->getnow();
					}
					auto noww=pq.top();
					pq.pop();
					auto nxt=Merge(now,noww);
					pq.push(nxt);					
				}
			}
		}
		cur=q[i].k;
	}
	sort(q+1,q+1+k,cmpp);
	for(int i=1;i<=k;++i)cout<<q[i].ans<<"\n";
	return 0;
}