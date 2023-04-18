#include<iostream>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[35005];
int Min[105][35006<<2],col[105][35006<<2];
void push_col(int id,int rt){
	Min[id][rt<<1]+=col[id][rt];
	Min[id][rt<<1|1]+=col[id][rt];
	col[id][rt<<1]+=col[id][rt];
	col[id][rt<<1|1]+=col[id][rt];
	col[id][rt]=0;
}
void add(int l,int r,int rt,int nowl,int nowr,long long k,int id){
	if(nowl<=l&&r<=nowr){
		col[id][rt]+=k;
		Min[id][rt]+=k;
		return;
	}
	push_col(id,rt);
	int m=(l+r)>>1;
	if(nowl<=m)add(lson,nowl,nowr,k,id);
	if(nowr>m)add(rson,nowl,nowr,k,id);
	Min[id][rt]=min(Min[id][rt<<1],Min[id][rt<<1|1]);
}
long long query(int l,int r,int rt,int nowl,int nowr,int id){
	if(nowl<=l&&r<=nowr)return Min[id][rt];
	long long re=2147483647;
	push_col(id,rt);
	int m=(l+r)>>1;
	if(nowl<=m)re=min(re,query(lson,nowl,nowr,id));
	if(nowr>m)re=min(re,query(rson,nowl,nowr,id));
	return re;
}
int last[35005];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long ans;
	for(int i=1;i<=n;++i){
		if(last[a[i]]){
			for(int j=0;j<=m;++j)
				add(1,n+1,1,1,last[a[i]],i-last[a[i]],j);
		}
		last[a[i]]=i;
		add(1,n+1,1,i+1,i+1,2e9,0);
		for(int j=1;j<=m;++j){
			ans=query(1,n+1,1,1,i,j-1);
			add(1,n+1,1,i+1,i+1,ans,j);
		}
	}
	cout<<ans<<"\n";
	return 0;
}