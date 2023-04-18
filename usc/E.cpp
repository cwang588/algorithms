#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[2005][2005];
int Min[2005][2005<<2],col[2005][2005<<2];
void update(int rt,int id){
	Min[id][rt]=min(Min[id][rt<<1],Min[id][rt<<1|1]);
}
void build(int l,int r,int rt,int id){
	if(l==r){
		Min[id][rt]=a[id][l];
		return;
	}
	int m=(l+r)>>1;
	build(lson,id);
	build(rson,id);
	update(rt,id);
}
void push_col(int rt,int id){
	Min[id][rt<<1]+=col[id][rt];
	Min[id][rt<<1|1]+=col[id][rt];
	col[id][rt<<1]+=col[id][rt];
	col[id][rt<<1|1]+=col[id][rt];
	col[id][rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,int k,int id){
	if(nowl<=l&&r<=nowr){
		Min[id][rt]+=k;
		col[id][rt]+=k;
		return;
	}
	push_col(rt,id);
	int m=(l+r)>>1;
	if(nowl<=m)modify(lson,nowl,nowr,k,id);
	if(nowr>m)modify(rson,nowl,nowr,k,id);
	update(rt,id);
}
int query(int l,int r,int rt,int nowl,int nowr,int id){
	if(nowl<=l&&r<=nowr)return Min[id][rt];
	push_col(rt,id);
	int m=(l+r)>>1,re=2147483647;
	if(nowl<=m)re=min(re,query(lson,nowl,nowr,id));
	if(nowr>m)re=min(re,query(rson,nowl,nowr,id));
	return re;
}
int curmin[2005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			char t;
			cin>>t;
			a[i][j]=a[i][j-1];
			if(t=='(')++a[i][j];
			else --a[i][j];
		}
		build(1,n,1,i);
	}	
	bool ky=true;
	for(int i=1;i<=n;++i){
		int tot1=0,tot2=0;
		vector<int>nb,sb;
		for(int j=1;j<=n;++j){
			curmin[j]=query(1,n,1,i,i,j);
			if(curmin[j]>=2)nb.push_back(j),tot1+=curmin[j];
			if(curmin[j]<0) sb.push_back(j),tot2-=curmin[j];
		}
		int now=0;
		for(const auto &x:sb){
			while(now<nb.size()){
				if(curmin[nb[now]]>=2){
					if(curmin[nb[now]]>=-curmin[x]){
						int num=(-curmin[x]+1)/2*2;
						modify(1,n,1,i,n,num,x);
						modify(1,n,1,i,n,-num,nb[now]);
						curmin[x]+=num;
						curmin[nb[now]]-=num;
						break;
					}else{
						int num=(curmin[nb[now]]+1)/2;
						modify(1,n,1,i,n,num,x);
						modify(1,n,1,i,n,-num,nb[now]);
						curmin[x]+=num;
						curmin[nb[now]]-=num;
					}
				}
				++now;
			}
			if(curmin[x]<0){
				ky=false;
				break;
			}
		}
		if(ky==false){
			break;
		}
	}
	for(int i=1;i<=n;++i){
		if(query(1,n,1,n,n,i)!=0){
			ky=false;
			break;
		}
	}
	if(ky)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}