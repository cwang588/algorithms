#include<bits/stdc++.h>
using namespace std;
struct node{
	int to[10],col,divide,num,depth;
	long long tot;
	void init(){
		col=num=0;
		tot=0;
		memset(to,0,sizeof(to));
	}
}T[2000005];
int cnt,tmp[15];
long long mi[15];
void work(long long x){
	for(int i=0;i<=9;++i){
		tmp[i]=x%10;
		x/=10;
	}
}
void update(int now){
	T[now].tot=0;
	for(int i=0;i<=9;++i){
		if(!T[now].to[i])continue;
		plus(T[now].tot,mi[T[now].to[i].depth-T[now].to]T[T[now].to[i]].cnt);
	}
}
void push_col(int nowm){
	if(!T[now].col)return;
	for(int i=0;i<=9;++i){
		if(!T[now].to[i])continue;
		T[T[now].to[i]].tot/=mi[T[now].col];
		T[T[now].to[i]].col+=T[now].col;
		T[T[now].to[i]].divide+=T[now].col;
	}
	T[now].col=0;
}
void add_dfs(int now,int depth){
	if(!depth)return;
	push_col(now);
	int t=now;
	if(!T[now].to[tmp[depth-1]]){
		T[now].to[tmp[depth-1]]=++cnt;
		now=cnt;
		T[now].init();
		++T[now].num;
		T[now].tot=tmp[pos-1]*mi[pos-1]*;
	}
	else{
		now=T[now].to[tmp[pos]];
		++T[now].num;
		T[now].tot+=tmp[pos-1]*mi[pos-1];
		T[now].tot%=tmp[pos];
	}
	add_dfs(now,pos-1);
	update(t);
}
void add(long long x){
	work(x);
	add_dfs(root,10);
}
long long query(long long x){
	long long re=0;
	work(x);
	for(int now=root,i=9;i>=0;--i){
		bool ky=false;
		for(int j=9-tmp[i];j>=-tmp[i];--j){
			int k=(j>=0?j:j+9);
			if(!T[now].to[k])continue;
			ky=true;
			re+=(tmp[i]+j)*mi[i];
			now=T[now].to[k];
		}
		if(!ky)return re;
	}
}
void shift(){
	++T[root].col;
	++T[root].divide;
	T[root].tot/=10;
	root=++cnt;
	T[cnt].init();
	T[cnt].depth=10;
}
int main(){
	mi[0]=1;
	for(int i=1;i<=10;++i)mi[i]=mi[i-1]*10;
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		cin>>n>>m;
		cnt=0;
		root=++cnt;
		T[cnt].init();
		T[cnt].depth=10;
		for(int i=1;i<=n;++i){
			long long tmp;
			cin>>tmp;
			add(tmp);
		}
		for(int i=1;i<=m;++i){
			string type;
			cin>>type;
			if(type=="Add"){
				long long x;
				cin>>x;
				add(x);
			}
			else if(type=="Query"){
				long long x;
				cin>>x;
				cout<<query(x)<<"\n";
			}
			else if(type=="Shift")shift();
			else if(type)
		}
	}
	
	return 0;
}