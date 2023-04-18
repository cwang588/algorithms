#include <bits/stdc++.h>
using namespace std;
struct dat{
	int li,ri,id;
}seg[205005];
struct LCR{
	int wi,ki,di;
	friend bool operator <(const LCR &a,const LCR &b){
		return a.wi>b.wi;
	}
}op,ls;
priority_queue<LCR>que;
int T;
int n,k;
int ans=0;
int vi[205005];
int CL,CR,NL,NR;
bool cmp(dat x,dat y)
{
	if(x.li!=y.li)return x.li<y.li;
	else return x.ri<y.ri;
}
int main()
{
	int i,j,k,l,r;
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++){
			scanf("%d%d",&l,&r);
			seg[i].li=l;
			seg[i].ri=r;
			seg[i].id=i;
		}
		sort(seg+1,seg+1+n,cmp);
		for(i=1;i<=k;i++){
			vi[seg[i].id]=i;
			op.wi=seg[i].ri;
			op.ki=i;
			op.di=seg[i].id;
			que.push(op);
		}
		NL=seg[k].li;
		ls=que.top();
		NR=ls.wi;
		if(NL<NR)ans=NR-NL;
		for(i=k+1;i<=n;i++){
			CL=NL;
			CR=NR;
			ls=que.top();
			vi[seg[i].id]=ls.ki;
			op.wi=seg[i].ri;
			op.ki=ls.ki;
			op.di=seg[i].id;
			que.pop();
			que.push(op);
			ls=que.top();
			NL=seg[i].li;
			NR=ls.wi;
			if(NL<NR){
				if((NL<CR)&&(CL<CR)){
					if(NR>CR){
						ans+=(NR-CR);
					}
				}
				else{
					ans+=(NR-NL);
				}
			}
		}
		printf("%d\n",ans);
		for(i=1;i<n;i++)printf("%d ",vi[i]);
		printf("%d\n",vi[n]);
	}
	return 0;
}