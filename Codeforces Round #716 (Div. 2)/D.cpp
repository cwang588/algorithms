#include<bits/stdc++.h>
using namespace std;
struct query{
	int l,r,lw,rw,id,ans;
}q[300005];
bool cmp(query x,query y){
	if(x.lw!=y.lw)return x.lw<y.lw;
	return x.r<y.r;
}
bool cmpp(query x,query y){
	return x.id<y.id;
}
int a[300005],cnt[300005],tmpcnt[300005];
int main(){
	int n,m,base;
	scanf("%d%d",&n,&m);
	base=sqrt(n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].lw=(q[i].l-1)/base+1;
		q[i].rw=(q[i].r-1)/base+1;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	int l=1,r=0,tmpmax;
	for(int i=1;i<=m;++i){
		int len=q[i].r-q[i].l+1;
		if(q[i].lw==q[i].rw){
			for(int j=q[i].l;j<=q[i].r;++j){
				++tmpcnt[a[j]];
				if(tmpcnt[a[j]]>(len-1)/2+1)q[i].ans=tmpcnt[a[j]];
			}
			for(int j=q[i].l;j<=q[i].r;++j)--tmpcnt[a[j]];
		}
		else{
			if(q[i].lw>q[i-1].lw||q[i-1].lw==q[i-1].rw){
				memset(cnt,0,sizeof(cnt));
				for(int j=q[i].l;j<=q[i].r;++j){
					++cnt[a[j]];
					if(cnt[a[j]]>(len-1)/2+1)q[i].ans=cnt[a[j]];
				}
				r=q[i].r;
				for(int j=q[i].lw*base;j>=q[i].l;--j)--cnt[a[j]];
				tmpmax=0;
				for(int j=1;j<=n;++j)tmpmax=max(tmpmax,cnt[j]);
			}
			else{
				bool ky=false;
				while(r<q[i].r){
					++r;
					++cnt[a[r]];
					if(cnt[a[r]]>tmpmax)tmpmax=cnt[a[r]];
				}
				int tmp=tmpmax;
				l=q[i].lw*base+1;
				while(l>q[i].l){
					--l;
					++cnt[a[l]];
					if(cnt[a[l]]>tmpmax)tmpmax=cnt[a[l]];
				}
				q[i].ans=tmpmax;
				tmpmax=tmp;
				while(l<=q[i].lw*base){
					--cnt[a[l]];
					++l;
				}
			}
		}
	}
	sort(q+1,q+1+m,cmpp);
	for(int i=1;i<=m;++i){
		int len=q[i].r-q[i].l+1;
		printf("%d\n",max(1,2*q[i].ans-len));
	}
	return 0;
}
