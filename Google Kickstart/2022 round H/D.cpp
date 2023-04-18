#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int x[100050],y[100005],c[100005];
vector<int>pos[100005];
unordered_map<long long,long long>value;
long long getpos(int x,int y){
	return 1ll*x*1000000+y;
}
long long Max[2][100005<<2],col[2][100005<<2];
void build(int l,int r,int rt){
	if(l==r){
		Max[0][rt]=Max[1][rt]=-1e18;
		col[0][rt]=col[1][rt]=0;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Max[0][rt]=Max[1][rt]=-1e18;
	col[0][rt]=col[1][rt]=0;
}
void push_col(int rt,int id){
	Max[id][rt<<1]+=col[id][rt];
	Max[id][rt<<1|1]+=col[id][rt];
	col[id][rt<<1]+=col[id][rt];
	col[id][rt<<1|1]+=col[id][rt];
	col[id][rt]=0;
}
void add(int l,int r,int rt,int nowl,int nowr,long long k,int id){
	if(nowl<=l&&r<=nowr){
		Max[id][rt]+=k;
		col[id][rt]+=k;
		return;
	}
	push_col(rt,id);
	int m=(l+r)>>1;
	if(nowl<=m)add(lson,nowl,nowr,k,id);
	if(nowr>m)add(rson,nowl,nowr,k,id);
	Max[id][rt]=max(Max[id][rt<<1],Max[id][rt<<1|1]);
}
long long query(int l,int r,int rt,int nowl,int nowr,int id){
	if(nowl<=l&&r<=nowr)return Max[id][rt];
	push_col(rt,id);
	int m=(l+r)>>1;
	long long re=-1e18;
	if(nowl<=m)re=max(re,query(lson,nowl,nowr,id));
	if(nowr>m)re=max(re,query(rson,nowl,nowr,id));
	return re;
}
void update(int l,int r,int rt,int pos,long long k,int id){
	if(l==r){
		Max[id][rt]=max(Max[id][rt],k);
		return;
	}
	push_col(rt,id);
	int m=(l+r)>>1;
	if(pos<=m)update(lson,pos,k,id);
	else update(rson,pos,k,id);
	Max[id][rt]=max(Max[id][rt<<1],Max[id][rt<<1|1]);
}
long long Max0[100005],Max1[100005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		value.clear();
		v.clear();
		build(1,100001,1);
		int n;
		long long e;
		cin>>n>>e;
		for(int i=1;i<=n;++i){
			cin>>x[i]>>y[i]>>c[i];
			++x[i];
			v.push_back(y[i]);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		long long ans=0;
		for(int i=1;i<=v.size();++i)pos[i].clear();
		for(int i=1;i<=n;++i){
			pos[getid(y[i])].push_back(x[i]);
			value[getpos(x[i],getid(y[i]))]+=c[i];
		}
		update(1,100001,1,1,0,0);
		update(1,100001,1,1,-e,1);
		for(int i=v.size();i>=1;--i){
			long long sum=0,tot=0;
			sort(pos[i].begin(),pos[i].end());
			pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
			for(auto &xpos:pos[i])tot+=value[getpos(xpos,i)];
			for(int j=0;j<pos[i].size();++j)Max0[j]=Max1[j]=-1e18;			
			for(int j=0;j<pos[i].size();++j){
				int now=pos[i][j];
				sum+=value[getpos(now,i)];
				add(1,100001,1,1,now,value[getpos(now,i)],0);
				Max0[j]=max(Max0[j],query(1,100001,1,1,now,0));
				Max0[j]=max(Max0[j],query(1,100001,1,1,now,1)+sum-e);
				Max1[j]=max(Max1[j],query(1,100001,1,1,now,0)+tot-sum-e);
			}
			for(int j=0;j<pos[i].size();++j)add(1,100001,1,1,pos[i][j],-value[getpos(pos[i][j],i)],0);
			sum=0;
			for(int j=pos[i].size()-1;j>=0;--j){
				int now=pos[i][j];
				sum+=value[getpos(now,i)];
				add(1,100001,1,now,100001,value[getpos(now,i)],1);
				Max1[j]=max(Max1[j],query(1,100001,1,now,100001,1));
				Max1[j]=max(Max1[j],query(1,100001,1,now,100001,0)+sum-e);
				Max0[j]=max(Max0[j],query(1,100001,1,now,100001,1)+tot-sum-e);
			}
			for(int j=pos[i].size()-1;j>=0;--j)add(1,100001,1,pos[i][j],100001,-value[getpos(pos[i][j],i)],1);
			long long t0=query(1,100001,1,1,100001,0),t1=query(1,100001,1,1,100001,1);
			for(int j=0;j<pos[i].size();++j){
				Max0[j]=max(Max0[j],t0+tot-2*e);
				Max1[j]=max(Max1[j],t1+tot-2*e);
				Max0[j]=max(Max0[j],Max1[j]-e);
				Max1[j]=max(Max1[j],Max0[j]-e);
				ans=max(ans,Max0[j]);
				ans=max(ans,Max1[j]);
				update(1,100001,1,pos[i][j],Max0[j],0);
				update(1,100001,1,pos[i][j],Max1[j],1);
			}
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	return 0;
}