#include<bits/stdc++.h>
using namespace std;
int a[300005];
map<int,int>num;
struct query{
	int l,r,id,ans,k;
}q[300005];
bool cmp(query x,query y){
	return x.l<y.l;
}
bool cmpp(query x,query y){
	return x.id<y.id;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;++i){
		while(r<q[i].r)++num[a[++r]];
		while(l<q[i].l)--num[a[l++]];
		q[i].ans=num[q[i].k];
	}
	sort(q+1,q+1+m,cmpp);
	for(int i=1;i<=m;++i)printf("%d\n",q[i].ans);
	return 0;
}
