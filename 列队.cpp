#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600005;
struct Value{
	long long l,r,val;
};
struct node{
	int son[2],tot,key,sz;
	Value val;
}T[N<<2];
bool operator < (const Value &a,const Value &b){
	if(a.val!=b.val)return a.val<b.val;
	return a.l<b.l;
}
bool operator == (const Value &a,const Value &b){
	if(a.val==b.val&&a.l==b.l&&a.r==b.r)return true;
	return false;
}
int cnt;
int getrand(){return (rand()%32768)*32768+rand()%32768;}
int newnode(long long l,long long r,int val){
	++cnt;
	T[cnt].val=Value{l,r,val};
	T[cnt].son[0]=T[cnt].son[1]=0;
	T[cnt].tot=r-l+1;
	T[cnt].sz=1;
	T[cnt].key=getrand();
	return cnt;
}
struct treap{
	int root,x,y,z;
	void update(int now){
		T[now].tot=T[T[now].son[0]].tot+T[T[now].son[1]].tot+T[now].val.r-T[now].val.l+1;
		T[now].sz=T[T[now].son[0]].sz+T[T[now].son[1]].sz+1;
	}
	void split_size(int now,int sz,int &x,int &y){
		if(!now)x=y=0;
		else{
			if(T[T[now].son[0]].sz<sz){
				x=now;
				split_size(T[now].son[1],sz-T[T[now].son[0]].sz-1,T[now].son[1],y);
			}
			else{
				y=now;
				split_size(T[now].son[0],sz,x,T[now].son[0]);
			}
			update(now);
		}
	}
	void split_value(int now,Value val,int &x,int &y){
		if(!now)x=y=0;
		else{
			if(T[now].val<val||T[now].val==val){
				x=now;
				split_value(T[now].son[1],val,T[now].son[1],y);
			}
			else{
				y=now;
				split_value(T[now].son[0],val,x,T[now].son[0]);
			}
			update(now);
		}
	}
	int merge(int x,int y){
		if(!x||!y)return x+y;
		if(T[x].key>T[y].key){
			T[x].son[1]=merge(T[x].son[1],y);
			update(x);
			return x;
		}
		else{
			T[y].son[0]=merge(x,T[y].son[0]);
			update(y);
			return y;
		}
	}
	void insert(Value val){
		split_value(root,val,x,y);
		root=merge(merge(x,newnode(val.l,val.r,val.val)),y);
	}
	void del(Value val){
		split_value(root,val,x,z);
		split_size(x,T[x].sz-1,x,y);
		assert(T[y].sz==1);
		y=0;
		root=merge(merge(x,y),z);
	}
	pair<int,int> find_value(int tot){
		int now=root;
		while(now){
			if(T[T[now].son[0]].tot<tot&&T[now].val.r-T[now].val.l+1+T[T[now].son[0]].tot>=tot)return make_pair(now,tot-T[T[now].son[0]].tot);
			if(T[T[now].son[0]].tot>=tot)now=T[now].son[0];
			else{
				tot-=T[now].val.r-T[now].val.l+1+T[T[now].son[0]].tot;
				now=T[now].son[1];
			}
		}
	//	assert(false);
	}
}column,row[600005];
int value[600005];
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
inline void write(long long x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
signed main(){
//	freopen("data.txt","r",stdin);
//	freopen("result.txt","w",stdout);
	srand(time(0));	
//	ios::sync_with_stdio(false);
	int n,m,q;
//	cin>>n>>m>>q;
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;++i){
		row[i].insert(Value{1ll*(i-1)*m+1,1ll*i*m-1,++value[i]});
		column.insert(Value{1ll*i*m,1ll*i*m,++value[n+1]});
	}
	for(int i=1;i<=q;++i){
		int x,y;
//		cin>>x>>y;
		x=read();y=read();
		if(y==m){
			auto pos=column.find_value(x);
			long long ans=T[pos.first].val.l;
			cout<<ans<<"\n";
			//write(ans);
			column.del(T[pos.first].val);
			column.insert(Value{ans,ans,++value[n+1]});
		}
		else{
			auto pos=row[x].find_value(y);
			long long ans=T[pos.first].val.l+pos.second-1;
			cout<<ans<<"\n";
			//write(ans);
			row[x].del(T[pos.first].val);
			if(ans!=T[pos.first].val.l){
				row[x].insert(Value{T[pos.first].val.l,ans-1,T[pos.first].val.val});
			}
			if(ans!=T[pos.first].val.r){
				row[x].insert(Value{ans+1,T[pos.first].val.r,T[pos.first].val.val});
			}
			column.insert(Value{ans,ans,++value[n+1]});
			pos=column.find_value(x);
			ans=T[pos.first].val.l;
			column.del(T[pos.first].val);
			row[x].insert(Value{ans,ans,++value[x]});
		}
	}
	return 0;
}