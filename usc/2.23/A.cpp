#include<bits/stdc++.h>
using namespace std;
double a[10005];
struct query{
	int l,r,lw,rw,id;
	bool ans;
}q[10005];
unordered_map<double,int>cnt;
int num[10005],Max;
void add(int x){
	++cnt[a[x]];
	--num[cnt[a[x]]-1],++num[cnt[a[x]]];
	Max=max(Max,cnt[a[x]]);
}
void del(int x){
	--cnt[a[x]];
	--num[cnt[a[x]]+1],++num[cnt[a[x]]];
	if(cnt[a[x]]+1==Max&&!num[cnt[a[x]]+1])--Max;
}
bool cmp1(query x,query y){
	if(x.lw==y.lw)return x.rw<y.rw;
	return x.lw<y.lw;
}
bool cmp2(query x,query y){
	return x.id<y.id;
}
int main(){
	int n,m;
	cin>>n>>m;
	int base=sqrt(n);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i){
		cin>>q[i].l>>q[i].r;
		q[i].lw=q[i].l/base,q[i].rw=q[i].r/base;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp1);
	int l=1,r=0;
	for(int i=1;i<=m;++i){
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		while(l>q[i].l)add(--l);
		while(l<q[i].l)del(l++);
		if(Max>=(r-l+1)/2+1)q[i].ans=true;
		else q[i].ans=false;
//		cout<<q[i].l<<" "<<q[i].r<<" "<<Max<<"\n";
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;++i){
		if(q[i].ans)cout<<"usable\n";
		else cout<<"unusable\n";
	}
	return 0;
}